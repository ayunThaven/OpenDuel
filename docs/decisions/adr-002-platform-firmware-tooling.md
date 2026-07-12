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
- explicit about hardware abstraction;
- robust enough for a physical device.

The first working prototype currently runs in Wokwi using an ESP32-S3, an
ILI9341 display, a rotary encoder and physical buttons.

OpenDuel should preserve Wokwi for quick experiments while moving the main
firmware toward a more robust ESP32-native development workflow.

## Decision

OpenDuel will use the ESP32-S3 as its initial target platform.

The main firmware project will use ESP-IDF.

ESP-IDF will be used as the primary framework and build system for the physical
device firmware.

Wokwi may still be used for isolated simulations, wiring validation and early
experiments, but it will not define the main firmware architecture.

The firmware implementation should be structured in a modular way and follow an
ESP-IDF-style component organization.

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

## Alternatives considered

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

PlatformIO would provide a cleaner project structure than the Arduino IDE and
better dependency management.

However, using PlatformIO with Arduino would still keep the project on top of the
Arduino framework. This would not fully match the long-term goal of building a
robust ESP32-native firmware architecture.

### Arduino IDE

The Arduino IDE is simple and beginner-friendly.

However, it is not suitable for the intended repository structure, modular source
layout, CI integration, component-based firmware design and long-term
maintainability.

### ESP-IDF with PlatformIO

PlatformIO can also be used with ESP-IDF.

However, OpenDuel will initially prefer the native ESP-IDF workflow to stay close
to Espressif documentation, examples and tooling.

This may be revisited later if PlatformIO brings a clear advantage for developer
experience or CI.

### Other microcontroller platforms

Other platforms such as RP2040, STM32 or classic ESP32 boards could be used.

However, ESP32-S3 provides a strong balance of availability, performance,
connectivity, GPIO count, ecosystem support and compatibility with the current
prototype direction.

## Consequences

### Positive

- ESP-IDF is the official Espressif framework for ESP32 development.
- The project starts with a firmware architecture suitable for a real embedded device.
- Advanced ESP32 features remain accessible.
- Future communication features can use native ESP-IDF capabilities.
- Task management and hardware abstraction can be designed properly from the beginning.
- The project is more credible as an embedded/IoT portfolio project.
- The firmware can grow beyond sketch-style prototyping.

### Negative

- ESP-IDF is more complex than Arduino for new contributors.
- Development setup is heavier than a simple Arduino or PlatformIO project.
- Some maker-oriented libraries may require adaptation or replacement.
- Wokwi prototypes may not map directly to the main firmware structure.
- Early development may be slower because more architecture must be defined upfront.

## Notes

This decision defines the initial firmware direction. It does not prevent future
support for Arduino-based experiments, Wokwi sketches or additional ESP32 boards.

The project should avoid coupling duel logic too tightly to ESP-IDF APIs so that
the core duel engine remains portable and testable.

A future ADR may revisit the tooling choice if the native ESP-IDF workflow becomes
too heavy for contributors or if another workflow provides clear benefits.