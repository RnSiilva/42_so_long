<h1 align="center">
  ✏️ so_long
</h1>

<p align="center">
	<b><i>And thanks for all the fish! 🐟</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/RnSiilva/42_so_long?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/RnSiilva/42_so_long?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/RnSiilva/42_so_long?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/RnSiilva/42_so_long?color=brightgreen" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
	<span> · </span>
	<a href="#-useful-links">Useful Links</a>
	<span> · </span>
	<a href="-game">Game Rules</a>
  <span> · </span>
	<a href="-controls">Controls</a>
</h3>

---

## 💡 About the project

> _This project is a very small 2D game.._

	🚀 TLDR: Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.

## 📑 Index

* [**📁 includes:**](so_long/include/) contains the program's headers.
* [**📁 srcs:**](so_long/src/) contains the source code of the program.
* [**📁 maps:**](so_long/maps/) contains maps that can be used and tested
* [**📁 libs:**](so_long/libs/) contains the source code of `libft` and `minilibx`.
* [**📁 imgs:**](so_long/img/) contains the .xpm and .png images used in the program.
* [**📁 my_tests and tutorials:**](tutorial_minilibx/) contains some test codes to improve knowledge.
* [**Makefile**](so_long/Makefile) - contains instructions for compiling the program and testing it.

_Note: only mandatory requirements of the project's subject are covered._

## 🕹️ About my game

This game is inspired by The Simpsons, in which Homer needs to eat all the donuts before leaving the house.

![Sem título](https://github.com/RnSiilva/42_so_long/blob/main/Screenshot.png)
## 🛠️ Usage

### Requirements

The program is written in C language for **Linux** distributions and thus needs the **`clang` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile the program, run:

```shell
$ make
```
This will compile the source files and generate the `so_long` executable.


**2. Executing the program**

To execute the program, run:

```shell
$ ./so_long <map>
```
Replace `<map>` with the path to the map file you want to use. The map file should have the `.ber` extension and follow the format specified in the project. Inside the `/maps` folder there are some examples of valid and invalid maps.

**3. Example**
```shell
$ ./so_long maps/42.ber
```

---
## Grade: 100 / 100

## 📋 Testing

You can use this third party tester to fully test the project:

- so_long_invalidator (Nuno-Jesus): https://github.com/Nuno-Jesus/so_long_invalidator

## 📌 Useful Links

* [[PISKEL] Sprite editor](https://www.piskelapp.com/)
* [[GITHUB] Install minilibx Ubuntu 18.04](https://gist.github.com/caio-vinicius/c082bf00b6b2d3c8aeb58f038af9b210)

## 📋 Game Rules
- The player starts at an initial position marked by a character.
- The goal is to collect all the items represented by collectibles (`C`) on the map.
- The player must avoid obstacles represented by walls (`1`) and enemies (`E`).
- The player can move in the up, down, left, and right directions using the arrow keys.
- The game ends when the player collects all the items and returns to the initial position or is captured by an enemy.
- The number of moves made by the player is displayed in the game window.

## 🎮 Controls
- `W`, `S`, `D`, `A` and `Arrow keys`: move the character in the up, down, left, and right directions.
- `ESC` key: exit the game.

