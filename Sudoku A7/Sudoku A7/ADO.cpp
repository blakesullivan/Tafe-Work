//Blake Sullivan - ADO.cpp
#include "ADO.h"

ADO::ADO()
{
	m_sPuzName = "";
	m_sDataBaseName = "";
	m_pSG = NULL;
	m_pConnection = NULL;

	DAM = "ADO";
}
ADO::~ADO()
{
	CoUninitialize();
}

void ADO::Init(std::string puzName, std::string dbName)
{
	m_sPuzName = puzName;
	m_sDataBaseName = dbName;

	if (ConnectToDB())
	{
		ADODB::_ConnectionPtr pConn("ADODB.Connection");
		m_pConnection = pConn;
	}
	//cout << "Leaving INIT\n";
}

bool ADO::ConnectToDB()
{
	hr = CoInitialize(NULL);
	if (FAILED(hr)) {
		cout << DAM << ": Failed to CoInitialize() COM." << endl;
		return false;
	}
	else
		{return true;}
}
bool ADO::OpenConnection()
{
	std::string sConnect = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=";
	sConnect += GetWorkingPath().c_str();
	sConnect += "\\";
	sConnect += m_sDataBaseName.c_str();
	_bstr_t bstrConnect = sConnect.c_str();

	hr = m_pConnection->Open(bstrConnect, "admin", "", ADODB::adConnectUnspecified);
	return SUCCEEDED(hr);
}
bool ADO::CloseConnection()
{
	m_pConnection->Close();
	//cout << DAM << ": Cleanup. Done." << endl;
}

void ADO::SetupPuzzle(SudokuGrid* sg, std::string fromTable, std::string sPuzNum)
{
	m_pSG = sg;
	_bstr_t query;
	std::string tempQuery = "";
	ADODB::_RecordsetPtr pRS("ADODB.Recordset");
	//cout << "In SetupPuzzle\n";
	
	try
	{
		if (OpenConnection() == true)
		{
			//cout << DAM << ": Successfully connected to database. Data source name:\n  " << m_pConnection->GetConnectionString() << endl;
			// Prepare SQL query.
            tempQuery = "SELECT Col1, Col2, Col3, Col4, Col5, Col6, Col7, Col8, Col9 FROM ";
			tempQuery += fromTable.c_str();
			tempQuery += " WHERE Game = ";
			tempQuery += sPuzNum;
			if (fromTable.c_str() == "CurrentPuzzle")
			{
				tempQuery += " AND OwnerID=1";
			}
			tempQuery += " ORDER BY Row ASC;";
			query = tempQuery.c_str();
           // cout << DAM << ": SQL query:\n  " << query << endl;

			hr = pRS->Open(query,
							_variant_t((IDispatch *) m_pConnection, true), 
							ADODB::adOpenUnspecified,
							ADODB::adLockUnspecified, 
							ADODB::adCmdText);
			if (SUCCEEDED(hr))
			{
				//cout << DAM << ": Retrieve schema info for the given result set: " << endl;
				ADODB::Fields* pFields = NULL;
                hr = pRS->get_Fields(&pFields);
                if (SUCCEEDED(hr) && pFields && pFields->GetCount() > 0) {
                    for (long nIndex=0; nIndex < pFields->GetCount(); nIndex++) {
                       // cout << " | " << _bstr_t(pFields->GetItem(nIndex)->GetName());
                    }
                    //cout << endl;
                }
                else {
                    cout << DAM << ": Error: Number of fields in the result set is 0." << endl;
                }
				
				//cout << DAM << ": Fetch the actual data: " << endl;
				int rowCount = 0;
				while (!pRS->AdoNSEOF)
				{
					for (long nIndex = 0; nIndex < pFields->GetCount(); nIndex++)
					{
						//cout << " | " << _bstr_t(pFields->GetItem(nIndex)->GetValue());
						m_pSG->SetSquare((rowCount * 9) + nIndex, pFields->GetItem(nIndex)->GetValue(), false);
                    }
                    //cout << endl;
                    pRS->MoveNext();
                    rowCount++;
				}
				//cout << DAM << ": Total Row Count: " << rowCount << endl;
			}
			pRS->Close();
			CloseConnection();
		}
		else
		{
			cout << DAM << ": Unable to connect to data source." << endl;
		}
	}
	catch(_com_error& e) 
	{
        cout << DAM << ": _com_error: " << e.Description() << endl;
    }

	
}
void ADO::OutputCurrent(SudokuGrid* sg, std::string sPuzNum, std::string id)
{
	m_pSG = sg;
	_bstr_t query;
	std::string tempQuery = "";
	ADODB::_RecordsetPtr pRS("ADODB.Recordset");
	bool bUpdate = false;
	int rowCount = 0;
	//cout << "In SetupPuzzle\n";
	//ADODB::_CommandPtr pCM("ADODB.Command");
	
	try
	{
		if (OpenConnection() == true)
		{
			//([OwnerID],[Game],[Row],[Col1],[Col2],[Col3],[Col4],[Col5],[Col6],[Col7],[Col8],[Col9])
			tempQuery = "SELECT Col1, Col2, Col3, Col4, Col5, Col6, Col7, Col8, Col9 FROM CurrentPuzzle WHERE OwnerID=";
			tempQuery += id;
			tempQuery += " AND Game=";
			tempQuery += sPuzNum;
			tempQuery += " ORDER BY Row ASC;";
			query = tempQuery.c_str();
			//cout << DAM << ": SQL query:\n  " << query << endl;

			hr = pRS->Open(query,
						_variant_t((IDispatch *) m_pConnection, true), 
						ADODB::adOpenUnspecified,
						ADODB::adLockUnspecified, 
						ADODB::adCmdText);

			if (SUCCEEDED(hr))
			{
				while (!pRS->AdoNSEOF)
				{
					pRS->MoveNext();
                    rowCount++;
				}
				//cout << "RowCount: " << rowCount << endl;
				if (rowCount > 0)
				{
					bUpdate = true;
				}
				else
				{
					bUpdate = false;
				}
			}
			pRS->Close();

			for (int i = 0; i < 9; i++)
			{
				if (bUpdate == true)
				{
					tempQuery = "UPDATE CurrentPuzzle SET ";
					for (int j = 1; j < 10; j++)
					{
						tempQuery += "Col";
						tempQuery += _bstr_t(j);
						tempQuery += "=";
						tempQuery += _bstr_t(m_pSG->GetSquareFromGrid(i+1, j)->GetNum());
						if (j < 9) {tempQuery += ",";}
					}
					tempQuery += " WHERE OwnerID=";
					tempQuery += id;
					tempQuery += " AND Game=";
					tempQuery += sPuzNum;
					tempQuery += " AND Row=";
					tempQuery += _bstr_t(i);
					tempQuery += ";";
				}
				else
				{
					tempQuery = "INSERT INTO CurrentPuzzle VALUES ('";
					tempQuery += id;
					tempQuery += "','";
					tempQuery += sPuzNum;
					tempQuery += "','";
					tempQuery += _bstr_t(i);
					for (int j = 1; j < 10; j++)
					{
						tempQuery += "','";
						tempQuery += _bstr_t(m_pSG->GetSquareFromGrid(i+1, j)->GetNum());
					}
					tempQuery += "')";
				}
				
				query = tempQuery.c_str();
				//cout << DAM << ": SQL query:\n  " << query << endl;

				pRS->Open(query, 
						m_pConnection.GetInterfacePtr(), ADODB::adOpenForwardOnly,
						ADODB::adLockReadOnly, ADODB::adCmdText);

				//m_pConnection->Execute(query, NULL, ADODB::adExecuteNoRecords);

				/*if (SUCCEEDED(hr)) 
					{cout << "Table Updated." << endl;}
				else 
					{cout << "Updated Failed." << endl;}*/
			}

			CloseConnection();
		}
		else
		{
			cout << DAM << ": Unable to connect to data source." << endl;
		}
	}
	catch(_com_error& e) 
	{
        cout << DAM << ": _com_error: " << e.Description() << endl;
    }
}

std::string ADO::GetWorkingPath() 
{ 
   char temp[_MAX_PATH]; 
   return (_getcwd(temp, _MAX_PATH) ? std::string(temp) : std::string("")); 
} 