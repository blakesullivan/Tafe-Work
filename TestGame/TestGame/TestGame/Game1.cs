using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;

namespace TestGame
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    /// 
    class Ship
    {
        public Model Model;
        public Matrix[] Transforms;

        public Vector3 Position = Vector3.Zero;

        public Vector3 Velocity = Vector3.Zero;

        public Matrix RotationMatrix = Matrix.Identity;
        private float rotation;
        public int OldMouse;

        public float Rotation
        {
            get { return rotation; }
            set
            {
                float newVal = value;
                while (newVal >= MathHelper.TwoPi)
                {
                    newVal -= MathHelper.TwoPi;
                }
                while (newVal < 0)
                {
                    newVal += MathHelper.TwoPi;
                }

                if (rotation != newVal)
                {
                    rotation = newVal;
                    RotationMatrix = Matrix.CreateRotationY(rotation);
                }
            }
        }

        public void Update(KeyboardState KeyState, MouseState MouState)
        {
            Rotation -= (MouState.X - OldMouse) * 0.001f;
            OldMouse = MouState.X;
            if (KeyState.IsKeyDown(Keys.Up))
            {
                Velocity += RotationMatrix.Forward;
            }
        }
        public void Update(GamePadState GPState)
        {
            Rotation -= (GPState.ThumbSticks.Right.X * 0.01f);
            //Rotation -= (GPState.ThumbSticks.Right.X - OldMouse) * 0.01f;
            OldMouse = (int)GPState.ThumbSticks.Right.X;
            if ((GPState.IsButtonDown(Buttons.LeftThumbstickUp)) || (GPState.IsButtonDown(Buttons.DPadUp)))
            {
                Velocity += RotationMatrix.Forward;
            }

            if (GPState.IsButtonDown(Buttons.A))
            {
                GamePad.SetVibration(PlayerIndex.One, 1, 1);
            }
            else if (GPState.IsButtonDown(Buttons.B))
            {
                GamePad.SetVibration(PlayerIndex.One, 0, 1);
            }
            else if (GPState.IsButtonDown(Buttons.X))
            {
                GamePad.SetVibration(PlayerIndex.One, 1, 0);
            }
            else if (GPState.IsButtonDown(Buttons.Y))
            {
                GamePad.SetVibration(PlayerIndex.One, 0.1f, 0.1f);
            }
            else
            {
                GamePad.SetVibration(PlayerIndex.One, 0, 0);
            }
        }
    }

    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
        KeyboardState oldState;
        List<string> MBOPTIONS = new List<string>();

        Ship ship = new Ship();
        Texture2D Tex;

        Vector3 cameraPosition = new Vector3(0.0f, 0.0f, -5000.0f);
        Matrix projectionMatrix;
        Matrix viewMatrix;
        
        SpriteFont Font1;
        Vector2 FontPos;


        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here
            this.graphics.PreferredBackBufferWidth = 800;
            this.graphics.PreferredBackBufferHeight = 608;
            this.graphics.IsFullScreen = true;

            projectionMatrix = Matrix.CreatePerspectiveFieldOfView(
                MathHelper.ToRadians(45.0f),
                GraphicsDevice.DisplayMode.AspectRatio,
                1.0f, 10000.0f);
            viewMatrix = Matrix.CreateLookAt(cameraPosition,
                Vector3.Zero, Vector3.Up);
            
            base.Initialize();

            oldState = Keyboard.GetState();

            Tex = new Texture2D(GraphicsDevice, 800, 600);
        }

        private Matrix[] SetupEffectDefaults(Model myModel)
        {
            Matrix[] absoluteTransforms = new Matrix[myModel.Bones.Count];
            myModel.CopyAbsoluteBoneTransformsTo(absoluteTransforms);

            foreach (ModelMesh mesh in myModel.Meshes)
            {
                foreach (BasicEffect effect in mesh.Effects)
                {
                    effect.EnableDefaultLighting();
                    effect.Projection = projectionMatrix;
                    effect.View = viewMatrix;
                }
            }
            return absoluteTransforms;
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {

            ship.Model = this.Content.Load<Model>("Models/p1_wedge");
            ship.Transforms = SetupEffectDefaults(ship.Model);
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);
            Tex = this.Content.Load<Texture2D>("Title");
            Font1 = Content.Load<SpriteFont>("Tahoma");
            FontPos = new Vector2(20, 20);

            //FontPos = new Vector2(graphics.GraphicsDevice.Viewport.Width / 2, graphics.GraphicsDevice.Viewport.Height / 2);
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// all content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            // Allows the game to exit
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed)
                this.Exit();

            // TODO: Add your update logic here
            UpdateInput();

            ship.Position += ship.Velocity;

            ship.Velocity *= 0.95f;

            base.Update(gameTime);
        }

        private void UpdateInput()
        {
            if (GamePad.GetState(PlayerIndex.One).IsConnected == true)
            {
                ship.Update(GamePad.GetState(PlayerIndex.One));
            }
            else
            {
                KeyboardState newState = Keyboard.GetState();
                ship.Update(newState, Mouse.GetState());
                if (newState.IsKeyDown(Keys.Escape))
                {
                    if (!oldState.IsKeyDown(Keys.Escape))
                    {
                        //
                    }
                }
                else if (oldState.IsKeyDown(Keys.Escape))
                {
                    this.Exit();
                }
                
                oldState = newState;
            }
        }


        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.CornflowerBlue);

            Matrix shipTrasformMatrix = ship.RotationMatrix
               * Matrix.CreateTranslation(ship.Position);
            DrawModel(ship.Model, shipTrasformMatrix, ship.Transforms);

            spriteBatch.Begin();

            //Draw Hello World
            string output = "ThumbSticks.X: ";
            output += GamePad.GetState(PlayerIndex.One).ThumbSticks.Right.X;
            output += "\nOldMouse: ";
            output += ship.OldMouse;

            //Find the centre of the string
            //Vector2 FontOrigin = Font1.MeasureString(output) / 2;
            Vector2 FontOrigin = Font1.MeasureString(output) - Font1.MeasureString(output);
            //Draw the string;
            spriteBatch.DrawString(Font1, output, FontPos, Color.LightGreen, 0, FontOrigin, 1.0f, SpriteEffects.None, 0.5f);

            spriteBatch.End();

            base.Draw(gameTime);
        }

        public static void DrawModel(Model model, Matrix modelTransform,
            Matrix[] absoluteBoneTrasforms)
        {
            foreach (ModelMesh mesh in model.Meshes)
            {
                foreach (BasicEffect effect in mesh.Effects)
                {
                    effect.World =
                        absoluteBoneTrasforms[mesh.ParentBone.Index] *
                        modelTransform;
                }
                mesh.Draw();
            }
        }
    }
}
