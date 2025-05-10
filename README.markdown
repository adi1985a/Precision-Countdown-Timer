# Countdown Timer

## Description
A C++ Builder application using VCL to create a countdown timer. Starts from a specified number of seconds (default: 3666s), updates every second in HH:MM:SS format, and minimizes to the system tray. Displays "END OF TIME!" when the countdown reaches zero. Created by Adrian Lesniak.

## Features
- Countdown timer with HH:MM:SS display
- Updates every second (1s interval)
- Minimizes to system tray
- Stops and displays "END OF TIME!" at zero
- Graphical interface using VCL

## Requirements
- C++ Builder with VCL support
- Windows OS (uses system tray and VCL components)
- Form file (`*.dfm`) and header (`Unit1.h`) for GUI setup

## Installation
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Open the project in C++ Builder.
3. Ensure `Unit1.h` and the associated `.dfm` file are included.
4. Build and run the project.

## Usage
1. Launch the application.
2. The timer starts automatically from 3666 seconds (or modify `s` in code).
3. View the countdown in HH:MM:SS format on the GUI label.
4. Minimize to the system tray by clicking the tray icon to restore.
5. When the countdown reaches zero, it displays "END OF TIME!" and stops.

## Notes
- The countdown duration is hardcoded (`s = 3666`). Modify in `Unit1.cpp` to change.
- Requires VCL components (`TForm`, `TTimer`, `TLabel`, `TTrayIcon`).
- System tray functionality allows minimizing/restoring the app.
- Timer interval is set to 1000ms (1 second) in the form properties.

## Author
Adrian Lesniak

## License
MIT License