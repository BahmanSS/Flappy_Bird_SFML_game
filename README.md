# Flappy Bird — SFML Game (Learning Project)

This repository contains a simple **Flappy Bird clone**, implemented in C++ using the **SFML** library.  
The project was created as part of **learning SFML** and does not aim to be a fully polished or commercial game.

---
[![2025-08-19-012327.jpg](https://i.postimg.cc/NMxPZ028/2025-08-19-012327.jpg)](https://postimg.cc/jwLX7tXC)
[![2025-08-19-012355.jpg](https://i.postimg.cc/25Rc6W4F/2025-08-19-012355.jpg)](https://postimg.cc/w12c4747)

## 🎮 Game Description

Flappy Bird is a light arcade game where the player controls a bird.  
The goal is to keep the bird flying while avoiding obstacles (pipes) that move from right to left.  
The game ends when the bird collides with a pipe or the ground.  

---

## ✨ Features (Current State)

- **Basic controls**: make the bird jump with a key press.
- **Pipe generation**: randomly placed pipes moving with constant speed.
- **Score system**: points are awarded for passing pipes.
- **Save system**: stores best score in the `saves` folder.

---

## ⚙️ Build & Run

### Requirements
- C++ compiler (MSVC, GCC, or Clang)  
- **SFML** (Graphics, Window, System)  
- **CMake**  

---

### 🔹 Build & Run (Debug Version — for development)
This version includes debug symbols and is useful for testing and development.
```bash
git clone https://github.com/BahmanSS/Flappy_Bird_SFML_game.git
cd Flappy_Bird_SFML_game
cmake -B build
cmake --build build
.\build\bin\Debug\game.exe
```
###🔹 Build & Run (Release Version — optimized)
This version is optimized for performance and does not include debug symbols.
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
.\build\bin\Release\game.exe
```

## 💡 Notes            
Debug: good for testing, slower, contains extra debug info.      
Release: faster, optimized, best for playing the game.      
Both versions are created automatically in separate folders (Debug / Release) inside build/bin/.      

## 🎯 Controls        
Space — make the bird jump.            
Avoid pipes and ground collisions.                 
Game ends on collision, after which you can restart and try to beat your best score.


## 📂 Project Structure             
```
Flappy_Bird_SFML_game/
├── assets/         # Images, textures, sounds                 
├── include/        # Header files          
├── saves/          # Save data (best score)             
├── src/            # C++ source code        
├── CMakeLists.txt  # CMake configuration         
├── LICENSE.md      # License          
└── README.md       # This file                
```
