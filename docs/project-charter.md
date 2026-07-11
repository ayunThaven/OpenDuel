# OpenDuel Project Charter

## 1. Vision

OpenDuel is an open-source platform for building connected, modular and 3D-printable duel accessories.

The first target device is a wearable duel disk powered by ESP32, designed to track duel state, display life points, provide visual and audio feedback, and eventually synchronize with another device.

OpenDuel is not intended to be a simple cosplay prop. It is designed as a complete connected object combining embedded firmware, electronics, 3D printing, local networking, documentation and future dashboard integrations.

## 2. Goals

OpenDuel aims to provide:

- a reproducible open-source hardware and firmware project;
- a 3D-printable duel accessory;
- an ESP32-based embedded system;
- life point, turn and phase management;
- local operation without mandatory Internet access;
- synchronization between two devices;
- modular firmware architecture;
- extensible hardware design;
- clear documentation for makers and developers;
- a foundation for future dashboard, OBS and mobile integrations.

## 3. Non-goals

OpenDuel does not aim to:

- reproduce or distribute official licensed assets;
- include official logos, card artworks or proprietary game content;
- implement a complete official card rules engine in early versions;
- require modification of official cards;
- depend on cloud services to function;
- become a commercial product in its initial scope.

## 4. Project scope

### In scope for early versions

- ESP32-S3 firmware;
- Wokwi simulation;
- ILI9341 display support;
- rotary encoder and button inputs;
- addressable LED zones;
- basic duel state management;
- modular firmware architecture;
- printable mechanical prototypes;
- hardware BOM;
- assembly documentation.

### Out of scope for early versions

- full card recognition;
- motorized deployment;
- custom PCB;
- mobile application;
- online multiplayer;
- complete card database;
- battery-integrated final enclosure.

These features may be explored later once the core platform is stable.

## 5. Design principles

### 5.1 Open by default

OpenDuel should be documented and structured so that other makers can understand, reproduce and modify it.

### 5.2 Modular architecture

The duel engine must remain independent from hardware-specific modules.

For example, the core duel state should not know whether it is displayed on an ILI9341 screen, a web dashboard or an OBS overlay.

### 5.3 Offline-first

The device should work without Internet access.

Network features such as MQTT, dashboard integration or synchronization must enhance the experience, not be required for basic use.

### 5.4 No card modification requirement

The long-term goal is to avoid requiring users to modify official cards.

Temporary prototypes may use simplified input methods, but the project should keep non-invasive card recognition as a guiding principle.

### 5.5 Reproducible maker workflow

The project should include wiring diagrams, printable files, BOMs, assembly notes and firmware instructions.

A user with an ESP32, basic tools and a 3D printer should eventually be able to build the device by following the documentation.

### 5.6 Maintainable firmware

The firmware should avoid becoming a single large Arduino sketch.

The project will progressively move toward a structured PlatformIO-based C++ codebase.

## 6. Initial roadmap

### v0.1 — Wokwi prototype

- ESP32-S3 simulation;
- ILI9341 display;
- two-player life point tracking;
- phase management;
- turn management;
- rotary encoder controls;
- physical button controls;
- initial LED zone experimentation.

### v0.2 — Firmware architecture

- PlatformIO setup;
- `DuelEngine`;
- `DisplayManager`;
- `InputManager`;
- `LedManager`;
- configuration layer;
- basic code documentation.

### v0.3 — Hardware prototype

- breadboard wiring;
- real ESP32-S3;
- real ILI9341 display;
- real rotary encoder;
- real WS2812B LEDs;
- basic enclosure tests.

### v0.5 — Connected prototype

- two-device synchronization;
- ESP-NOW or local networking tests;
- basic MQTT integration;
- local dashboard prototype.

### v1.0 — Printable connected duel disk

- first complete 3D-printable device;
- documented assembly guide;
- stable firmware;
- complete BOM;
- reproducible build instructions.

## 7. Repository strategy

The repository follows a structured workflow:

- `main` is protected;
- all changes go through branches;
- changes are merged through pull requests;
- issues are used for meaningful tasks, bugs and feature planning;
- documentation is treated as part of the product.

Typical workflow:

```text
issue → branch → commit(s) → pull request → merge
```

## 8. Licensing strategy

The project should use separate licenses for different asset types when needed.

Recommended direction:

- firmware and software: permissive open-source license such as MIT;
- documentation: Creative Commons license;
- mechanical and hardware files: suitable open hardware license.

The exact licenses will be decided in a dedicated architecture decision record.

## 9. Legal and trademark disclaimer

OpenDuel is an independent fan-made open-source project.

It is not affiliated with, sponsored by or endorsed by Konami or any other rights holder.

No official logos, card artwork, proprietary names, copyrighted illustrations or licensed assets should be distributed in this repository.

## 10. Success criteria

OpenDuel will be considered successful if:

- the project can be built and understood by someone other than its original creator;
- the firmware remains modular and maintainable;
- the hardware can be reproduced from documentation;
- the device works offline for basic duel tracking;
- the project demonstrates a complete embedded IoT workflow;
- the repository can serve as a serious technical portfolio project.
