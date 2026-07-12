# OpenDuel

OpenDuel is an open-source platform for building connected, modular and
3D-printable duel accessories powered by ESP32.

The first target device is a wearable duel disk prototype designed for local,
offline play assistance: life point tracking, turn and phase management,
physical controls, display feedback and future synchronized devices.

OpenDuel is a fan-made maker project. It does not distribute official licensed
assets, logos, card artwork or proprietary content.

## Current status

OpenDuel is currently in its early prototyping phase.

The first prototype runs in Wokwi and currently supports:

- ESP32-S3;
- ILI9341 display;
- two-player life point tracking;
- turn and phase management;
- rotary encoder controls;
- physical buttons;
- preparation for addressable LED zones.

The repository foundation is being set up before moving to the first physical
hardware prototype.

## Project goals

OpenDuel aims to provide:

- fully 3D-printable duel accessories;
- ESP32-based embedded firmware;
- offline-first operation;
- synchronization between two devices;
- modular firmware architecture;
- addressable LED feedback;
- optional sound feedback;
- optional dashboard and OBS integration;
- card recognition experiments without modifying official cards;
- clear documentation for makers and contributors.

## Non-goals

OpenDuel does not aim to:

- implement a complete trading card game rules engine;
- distribute official logos, card artwork or proprietary assets;
- require Internet access to operate;
- require modification of official cards;
- become a commercial product in its initial phase.

## Repository structure

- `simulations/` — Wokwi prototypes and experiments;
- `firmware/` — ESP32 firmware source code;
- `hardware/` — electronics, schematics, wiring and bill of materials;
- `mechanical/` — CAD files, printable parts and mechanical prototypes;
- `docs/` — architecture, decisions, assembly and development documentation;
- `LICENSES/` — license notices for documentation and hardware assets.

## Documentation

Important project documents:

- `docs/project-charter.md` — project vision, scope and success criteria;
- `docs/development/repository-workflow.md` — GitHub workflow and contribution process;
- `docs/decisions/` — Architecture Decision Records;
- `LICENSES/README.md` — licensing overview.

## Roadmap

### v0.1 — Wokwi prototype

- ESP32-S3 simulation;
- ILI9341 display;
- life point tracking;
- turn and phase management;
- physical controls;
- first LED zone experiments.

### v0.2 — Firmware architecture

- PlatformIO project setup;
- modular firmware structure;
- duel state model;
- display manager;
- input manager;
- LED manager.

### v0.3 — Physical prototype

- real ESP32-S3 board;
- real display;
- physical buttons and encoder;
- addressable LEDs;
- basic enclosure tests.

### v0.5 — Connected prototype

- two-device synchronization;
- local communication;
- optional MQTT support;
- dashboard experiments.

### v1.0 — Printable connected duel disk

- complete printable device;
- stable firmware;
- assembly guide;
- wiring guide;
- bill of materials;
- reproducible build process.

## Licensing

OpenDuel uses multiple licenses depending on the type of content:

- firmware and software: MIT License;
- documentation: Creative Commons Attribution 4.0 International;
- hardware and mechanical design files: CERN Open Hardware Licence Version 2 - Permissive.

See `LICENSE` and `LICENSES/README.md` for details.

## Disclaimer

OpenDuel is an independent, fan-made open-source project.

It is not affiliated with, endorsed by, sponsored by or connected to Konami or
any other rights holder.

No official logos, card artwork, copyrighted illustrations, proprietary names
or licensed assets are distributed in this repository.