# C-Unplugged

Welcome to **C-Unplugged**, a fully functional, lightweight music library and playlist manager built entirely in C. 

##  What can it do?

* **Your Whole Library, Instantly:** It automatically loads all your available songs and their details right from a text file (`songs.txt`) when you start it up.
* **Albums That Actually Save:** You can create custom albums, add/remove songs, and browse them easily. The best part? **It remembers everything.** Your albums are saved locally, so they'll be right there waiting for you the next time you boot up.
* **Infinite Looping Playlists:** Build your queue by adding individual tracks or throwing entire albums into the mix. You can skip forward, go back, or remove songs on the fly. Once the playlist reaches the end, the music never stops—it seamlessly loops back to the beginning.
* **Super Simple Numbered Menus:** Nobody wants to type out full song titles in a terminal. C-Unplugged uses a clean, numbered menu system (1, 2, 3...) for everything. Under the hood, it uses unique secret IDs to keep track of your tunes securely without bothering you with the details.
* **Keeps the Receipts:** Every command you run is logged into a `log.txt` file. This log survives across sessions, meaning you can always look back at exactly what you (or anyone else) did during previous runs.

---

##  How to Compile and Run

Ready to get the music playing? It's super easy. 

### What you need first
You just need a standard C compiler (like `gcc`) and the `make` utility installed on your computer. If you're on Mac or Linux, you likely already have these!

### Step 1: Compile the Code
Open your terminal, navigate to the folder containing this project, and simply type:

```bash
make
