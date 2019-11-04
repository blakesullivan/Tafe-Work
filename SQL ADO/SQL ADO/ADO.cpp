// This source code demonstrates how to connect to Access 2007
// .accdb database from C++ using the ADO Data Access Technology.
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This sample code is provided to illustrate a concept and 
// should not be used in applications or Web sites, as it 
// may not illustrate the safest coding practices. Microsoft 
// assumes no liability for incidental or consequential damages 
// should the sample code be used for purposes 
// other than as intended.

#import <C:\\Program Files\\Common Files\\System\\ado\\msado15.dll> rename("EOF", "AdoNSEOF")

#include <iostream>
#include <tchar.h>
using namespace std;

#include <direct.h>

int _tmain(int argc, _TCHAR* argv[]) {
	// Data Access Method used in this sample
	const char* DAM = "ADO";

	// Connection string for ADO
	std::string sConnect = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=";
	sConnect += GetWorkingPath().c_str();
	sConnect += "\\Northwind 2007.accdb;";

	_bstr_t bstrConnect = sConnect.c_str();

    // Initialize the Component Object Module Library (COM)
    HRESULT hr = CoInitialize(NULL);
    if (FAILED(hr)) {
        cout << DAM << ": Failed to CoInitialize() COM." << endl;
        return hr;
    }

    // COM errors are handled by C++ try/catch block
    try {
        ADODB::_ConnectionPtr pConn("ADODB.Connection");
        hr = pConn->Open(bstrConnect, "admin", "", ADODB::adConnectUnspecified);
        if (SUCCEEDED(hr)) {
            cout << DAM << ": Successfully connected to database. Data source name:\n  "
                << pConn->GetConnectionString() << endl;

            // Prepare SQL query.
            _bstr_t query = "SELECT Customers.[Company], Customers.[First Name] FROM Customers;";
            cout << DAM << ": SQL query:\n  " << query << endl;

            // Excecute the query and create a record set
            ADODB::_RecordsetPtr pRS("ADODB.Recordset");
            hr = pRS->Open(query, 
                    _variant_t((IDispatch *) pConn, true), 
                    ADODB::adOpenUnspecified,
                    ADODB::adLockUnspecified, 
                    ADODB::adCmdText);
            if (SUCCEEDED(hr)) {
                cout << DAM << ": Retrieve schema info for the given result set: " << endl;
                ADODB::Fields* pFields = NULL;
                hr = pRS->get_Fields(&pFields);
                if (SUCCEEDED(hr) && pFields && pFields->GetCount() > 0) {
                    for (long nIndex=0; nIndex < pFields->GetCount(); nIndex++) {
                        cout << " | " << _bstr_t(pFields->GetItem(nIndex)->GetName());
                    }
                    cout << endl;
                }
                else {
                    cout << DAM << ": Error: Number of fields in the result set is 0." << endl;
                }

                cout << DAM << ": Fetch the actual data: " << endl;
                int rowCount = 0;
                while (!pRS->AdoNSEOF) {
                    for (long nIndex=0; nIndex < pFields->GetCount(); nIndex++) {
                        cout << " | " << _bstr_t(pFields->GetItem(nIndex)->GetValue());
                    }
                    cout << endl;
                    pRS->MoveNext();
                    rowCount++;
                }
                cout << DAM << ": Total Row Count: " << rowCount << endl;
            }
            
            pRS->Close();
            pConn->Close();
            cout << DAM << ": Cleanup. Done." << endl;
        }
        else {
            cout << DAM << ": Unable to connect to data source: " << bstrConnect << endl;
        }
    }
    catch(_com_error& e) {
        cout << DAM << ": _com_error: " << e.Description() << endl;
    }

    // Release the Component Object Module Library (COM)
    CoUninitialize();
	system("PAUSE");
    return hr;
}

std::string GetWorkingPath() { 
   char temp[_MAX_PATH]; 
   return (_getcwd(temp, _MAX_PATH) ? std::string(temp) : std::string("")); 
} 
