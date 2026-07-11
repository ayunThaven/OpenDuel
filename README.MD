# OpenDuel

OpenDuel is an open-source platform for building connected and
3D-printable duel accessories powered by ESP32.

## Current status

The project is currently in its early prototyping phase.

The first prototype runs in Wokwi and currently supports:

- ESP32-S3
- ILI9341 display
- two-player life point tracking
- turn and phase management
- rotary encoder controls
- physical buttons
- preparation for addressable LED zones

## Project goals

- Fully 3D-printable hardware
- Offline operation
- Synchronization between two devices
- Modular firmware architecture
- Optional dashboard and OBS integration
- Card recognition without modifying official cards

## Repository structure

- `simulations/` — Wokwi prototypes
- `firmware/` — ESP32 firmware
- `hardware/` — electronics, schematics and BOM
- `mechanical/` — CAD and printable files
- `docs/` — architecture and assembly documentation

## Disclaimer

OpenDuel is an independent, fan-made open-source project.

It is not affiliated with or endorsed by Konami or any other rights holder.
No official logos, card artwork or proprietary assets are distributed in
this repository.