# ADR-002: Platform and firmware tooling

## Status

Proposed

## Context

OpenDuel is an ESP32-based open-source project that will combine embedded
firmware, physical controls, displays, addressable LEDs, audio feedback and
future local communication between devices.

The project needs a firmware platform and development workflow that are:

- suitable for a real embedded and IoT project;
- compatible with ESP32-S3 boards;
- maintainable over time;
- compatible with modular firmware architecture;
- suitable for local communication features;
- suitable for future power management work;
- compatible with future CI checks;
- accessible enough for makers and contributors;
- explicit about hardware abstraction;
- robust enough for a physical device.

The first working prototype currently runs in Wokwi using an ESP32-S3, an
ILI9341 display, a rotary encoder and physical buttons.

OpenDuel should preserve Wokwi for quick experiments while moving the main
firmware toward a more robust and reproducible development workflow.

The firmware should not remain a single sketch. It should evolve toward a
structured project with clear modules, reusable components and a clean separation
between duel logic and hardware-specific code.

## Decision

OpenDuel will use the ESP32-S3 as its initial target platform.

The main firmware framework will be ESP-IDF.

The initial firmware project environment will be PlatformIO.

PlatformIO will be used to manage the firmware project structure, build
configuration, board environment, dependency handling and future CI integration.

ESP-IDF will remain the actual firmware framework used by the application.

This means that OpenDuel will use:

- ESP32-S3 as the initial hardware target;
- ESP-IDF as the main firmware framework;
- PlatformIO as the firmware project environment;
- Wokwi for isolated simulations and early experiments.

Wokwi may still be used for validating wiring, basic input handling, display
logic and small prototypes before testing on physical hardware. However, Wokwi
will not define the main firmware architecture.

The firmware implementation should be structured in a modular way and remain
compatible with an ESP-IDF-oriented architecture.

The firmware architecture should separate core duel logic from hardware-specific
code.

Expected modules include:

- duel state and rules-independent duel logic;
- display handling;
- input handling;
- LED handling;
- sound handling;
- communication handling;
- configuration;
- hardware abstraction.

Arduino will not be used as the main firmware framework.

## Alternatives considered

### Native ESP-IDF workflow

Using native ESP-IDF with `idf.py`, CMake and the Espressif tooling would keep
the project very close to official Espressif documentation and examples.

This is a strong option for professional ESP32 development.

However, the native ESP-IDF setup can be heavier for contributors and less
convenient for a maker-oriented open-source repository. PlatformIO provides a
more approachable project entry point while still allowing OpenDuel to use
ESP-IDF as the firmware framework.

Native ESP-IDF may be reconsidered later if PlatformIO becomes limiting or if
the project needs a workflow closer to official Espressif tooling.

### Arduino framework for ESP32

Arduino for ESP32 is accessible, fast to prototype with and compatible with many
maker libraries.

However, OpenDuel aims to become a structured embedded and IoT project rather
than only a sketch-based prototype. Arduino may become limiting for advanced
networking, task management, power management, hardware abstraction and long-term
firmware architecture.

Arduino remains useful for quick experiments, but it will not be the primary
firmware framework.

### PlatformIO with Arduino

PlatformIO with Arduino would provide a clean project structure, easy builds and
dependency management.

However, this would still keep the firmware on top of the Arduino framework. It
would not fully match the long-term goal of building a robust ESP32-native
firmware architecture.

### Arduino IDE

The Arduino IDE is simple and beginner-friendly.

However, it is not suitable for the intended repository structure, modular source
layout, CI integration, component-based firmware design and long-term
maintainability.

### Other microcontroller platforms

Other platforms such as RP2040, STM32 or classic ESP32 boards could be used.

However, ESP32-S3 provides a strong balance of availability, performance,
connectivity, GPIO count, ecosystem support and compatibility with the current
prototype direction.

## Consequences

### Positive

- ESP-IDF provides a serious foundation for an embedded and IoT project.
- ESP32-S3 is a strong initial platform for connected duel accessories.
- PlatformIO makes the project easier to clone, build and reproduce.
- PlatformIO provides a clear `platformio.ini` entry point for contributors.
- Future CI checks can build the firmware with a simple and consistent command.
- The project can use ESP-IDF features while keeping a maker-friendly workflow.
- Wokwi can still be used for quick simulations and isolated experiments.
- The firmware can grow beyond sketch-style prototyping.
- The project is more credible as an embedded/IoT portfolio project.

### Negative

- ESP-IDF is more complex than Arduino for new contributors.
- PlatformIO adds another tool between the project and native ESP-IDF.
- Some ESP-IDF examples or documentation may need adaptation for PlatformIO.
- Some maker-oriented Arduino libraries may require replacement or adaptation.
- Wokwi prototypes may not map directly to the main firmware structure.
- Early development may be slower because more architecture must be defined upfront.

## Notes

This decision defines the initial firmware direction. It does not prevent future
support for Arduino-based experiments, Wokwi sketches or additional ESP32 boards.

The project should avoid coupling duel logic too tightly to ESP-IDF APIs so that
the core duel engine remains portable and testable.

PlatformIO is selected as the initial project environment, but ESP-IDF remains
the main firmware framework.

A future ADR may revisit the tooling choice if PlatformIO becomes limiting, if
native ESP-IDF provides a clear advantage, or if the contributor workflow needs
to change.