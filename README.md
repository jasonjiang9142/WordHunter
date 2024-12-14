# Word Hunter

**Word Hunter** is an engaging word-finding game where players compete against time to discover as many words as possible from a grid of letters. Sharpen your vocabulary, speed, and strategic thinking while enjoying the challenge!

## Rules

1. **Goal**: Find as many words as possible from the grid of letters.  
2. **Forming Words**:  
   - Words can be formed by connecting adjacent letters:  
     - Horizontally  
     - Vertically  
     - Diagonally  
   - Words must be at least **3 letters long** and cannot be reused.  
   - Only words that exist in the dictionary are valid.  
3. **Scoring**: Each word earns points based on its length.  
4. **Time Limit**: Players have a limited time to hunt for words.  
5. **Difficulty Modes**: Choose from three difficulty levels:  
   - [1] Easy  
   - [2] Medium  
   - [3] Hard  

## Features

- Interactive gameplay with real-time scoring and a timer.  
- Recursive algorithms (DFS and BFS) for word validation and grid traversal.  
- Multiple difficulty modes for added challenge.  
- Integrated unit tests using **Google Test (GTest)** for robust validation.  

## Technologies Used

- **C++** for core game logic.  
- **Google Test (GTest)** for testing.  
- Recursive algorithms (DFS, BFS) to ensure efficient and accurate gameplay.  

## Installation

1. Clone the repository:  
   ```bash
   git clone https://github.com/jasonjiang9142/WordHunter.git
   cd WordHunter
   ```

2. Build the project using the Makefile:  
   ```bash
   make
   ```

3. Run the program:  
   ```bash
   ./main
   ```

## Running Tests

The project uses **Google Test (GTest)** for testing. Follow these steps to execute the tests:

1. Navigate to the build directory:  
   ```bash
   cd build
   ```

2. Build the test suite:  
   ```bash
   make
   ```

3. Run the tests:  
   ```bash
   ctest
   ```

## How to Play

1. Launch the game:  
   ```bash
   ./main
   ```

2. Follow the on-screen prompts to choose a difficulty level and start the game.  
3. Form words by connecting adjacent letters on the grid.  
4. Submit words to earn points and try to maximize your score before time runs out.  

## Contributing

Contributions are welcome! If you’d like to improve Word Hunter, please fork the repository, make changes, and submit a pull request.  

## License

This project is licensed under the [MIT License](LICENSE).  

## Acknowledgments

- Thanks to the creators of **Google Test** for providing a robust testing framework.  
- Inspired by classic word-finding games and puzzles.
