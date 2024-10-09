# World Cup Team Management System

## Project Overview
This project involves developing a system to manage World Cup teams and match results, utilizing data structures like linked lists and queues. The system allows for team and player management, including creating matches and updating team and player details during the tournament.

## Features
- **Team Information Management**: Read and store team data, calculate points, and sort teams based on performance.
- **Player Roster Management**: Manage player rosters including starting players and substitutes.
- **Match Creation and Management**: Support for match creation, including handling of non-existent teams.
- **Dynamic Player Management**: Ability to switch players between starting and substitute roles, and manage red card penalties.

## Technical Requirements
- **Phase One**:
  1. **Team Data Handling**: Read team data from `teams.txt`, calculate team points, and sort using Radix Sort.
  2. **CRUD Operations**: Support adding, modifying, and deleting team data.
  3. **Output**: Print all team data in a formatted manner and save sorted data back to `teamsInfo.txt`.

- **Phase Two**:
  1. **Match Setup**: Users can create matches by selecting two teams.
  2. **Player Data Handling**: Read player data from `players.txt`, and manage starting players and substitutes using linked lists and queues.
  3. **Player Substitution and Penalties**: Manage in-game substitutions and penalties like red cards.
  4. **Display and Save Player Data**: Print starting player lists for teams and save updated player data to `playersInfo.txt`.

## Usage Instructions
- **Setup**:
  - Ensure that the `teams.txt` and `players.txt` files are placed in the correct directory before starting the program.
  - Compile and run the provided source code in an environment that supports C/C++.

- **Operation**:
  - Use the menu-driven interface to navigate through different functionalities such as adding or editing teams, creating matches, or managing players.
  - Follow on-screen prompts to perform desired actions.

## File Descriptions
- `teams.txt`: Initial team data including names, codes, and performance metrics.
- `players.txt`: List of players categorized by team with details on starting and substitute players.
- `teamsInfo.txt`: Sorted team information after processing.
- `playersInfo.txt`: Updated player information after match processing.

