# 42Cub3D

<p align="center">
  <img src="https://user-images.githubusercontent.com/94384240/170144677-24ff4d41-6e4a-491a-adfa-7dcf0eac630a.jpeg" alt="42 School Logo" width="300">
</p>

## 🕹️ 42 Cursus - Cub3D

Cub3D is the final C project in the 42 curriculum, where we implemented a basic raycasting engine inspired by *Wolfenstein 3D*.

This was a group project:
- **Raycasting & Graphics**: [José Maria Lebre](https://github.com/jlebre)
- **Parsing & Map Handling**: [mtavares](https://github.com/mtavares98)

The project took around **2 months** to complete, using the original textures from *Wolfenstein 3D*.

One of the biggest challenges was correctly mapping the X-coordinate of a texture onto a wall.

📜 To see the project subject, [click here](https://github.com/jlebre/42Cub3d/blob/main/cub3d.pdf)!

---

## 📸 Gallery

![Screenshot](https://github.com/jlebre/42Cub3d/assets/94384240/9f3cc16c-c1b0-47a7-9753-5d153b9ed2ac)

![Screenshot](https://github.com/jlebre/42Cub3d/assets/94384240/4c02b616-5d12-4026-8d53-98fb92f44621)

[Gameplay Video](https://github.com/jlebre/42Cub3d/assets/94384240/6084f44a-c4c4-429c-b9b1-3fb7c150e839)

[Another Gameplay Video](https://github.com/jlebre/42Cub3d/assets/94384240/bcba92b7-983e-44a1-a111-9cd4b3bd9840)

---

## ⚙️ Installation

Install [MLX](https://github.com/42Paris/minilibx-linux):  
```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
git clone https://github.com/42Paris/minilibx-linux.git && cd minilibx-linux && ( [ -f ./configure ] && ./configure || true ) && make && sudo cp libmlx.a /usr/local/lib/ && [ -f libmlx_$(uname -m).a ] && sudo cp libmlx_$(uname -m).a /usr/local/lib/ || true && sudo cp mlx.h /usr/local/include/ && sudo mkdir -p /usr/local/man/man3 && sudo cp man/man3/mlx*.1 /usr/local/man/man3
```

```bash
git clone https://github.com/jlebre/42Cub3d.git
cd 42Cub3d/
make
```

To run the game:
```bash
./cub3d "map"
```

Available maps:
```bash
./cub3d basic.cub
./cub3d info.cub
```

You can create custom maps as long as they follow the constraints in **The Assignment** section.

To compile and run `basic.cub` in one command:
```bash
make a
```

---

## 📜 The Assignment

The goal was to build a **3D labyrinth game with first-person view**, inspired by *Wolfenstein 3D*.

### Key Requirements
- **Use MiniLibX** for rendering.
- **Smooth window management** (switching, minimizing, etc.).
- **Textured walls** that vary based on orientation (N, S, E, W).
- **Custom floor & ceiling colors.**
- **Keyboard controls:**
  - `W, A, S, D` → Move player
  - `←, →` → Rotate view
  - `ESC` → Exit game
- **Clicking the window’s close button should properly exit.**
- **Parse `.cub` files** for game settings & map layout.
- **The map must be enclosed by walls** (`1` for walls, `0` for empty space, `N/S/E/W` for player spawn position).

Example of a valid `.cub` map:
```plaintext
111111
100101
101001
1100N1
111111
```

### Texture & Color Configuration
```plaintext
NO ./path_to_north_texture
SO ./path_to_south_texture
WE ./path_to_west_texture
EA ./path_to_east_texture

F 220,100,0
C 225,30,0
```

If any error is found in the configuration file, the program must exit with:
```plaintext
Error
[Description of the issue]
```

---

## 🎮 Features
✔️ **Working compass**

✔️ **Minimap FOV matches actual player vision**

✔️ **Pause menu (`P` key)**

✔️ **Toggle minimap (`M` key)**

✔️ **Lives system (press `-` to lose a life, game stops at 0)**

⚠️ The settings icon is not functional.

---

## 🏆 Final Grade: **115/100**
We completed 3 out of 5 possible bonus features:

✔️ **Wall collisions**

✔️ **Mini-map system**

✔️ **Move FOV with mouse**

![Screenshot](https://github.com/jlebre/42Cub3d/assets/94384240/475636ea-68f0-4c38-95ac-b007bd2d68fd)

---

## 🎤 Conclusion
This was one of the most enjoyable projects I’ve worked on! Seeing visual progress made it extra rewarding.

This might be my favorite project so far, and I’d love to add more features in the future. 🚀
