# ADR-001: Licensing strategy

## Status

Proposed

## Context

OpenDuel is an open-source project combining multiple types of assets:

- firmware and software code;
- documentation;
- electronic design files;
- mechanical design files;
- 3D-printable files;
- bill of materials;
- possible branding assets.

Using a single license for every part of the repository would be simple, but not ideal.

Software, documentation and hardware files usually have different licensing needs. OpenDuel should therefore define a clear licensing strategy from the beginning.

The project must also avoid distributing any official licensed assets, logos, card artworks or proprietary content from existing trading card game franchises.

## Decision

OpenDuel will use a multi-license strategy.

The recommended licenses are:

- firmware and software: MIT License;
- documentation: Creative Commons Attribution 4.0 International;
- hardware, electronics and mechanical design files: CERN Open Hardware Licence Version 2 - Permissive.

Each major repository area should clearly state which license applies to it.

A root `LICENSE` file may be used for the main software license, while additional license files or notices may be added for documentation and hardware assets.

## Alternatives considered

### Single MIT license for everything

This would be simple and easy to understand.

However, MIT is designed for software and is not ideal for documentation, CAD files, PCB files or physical hardware designs.

### GPL for firmware

GPL would ensure that derivative firmware remains open source.

However, OpenDuel aims to be easy to reuse and integrate. A permissive license is more appropriate for the early project goals.

### Creative Commons for the whole repository

Creative Commons licenses are suitable for documentation and creative works.

However, they are not recommended for software source code.

### CERN-OHL-S for hardware files

CERN-OHL-S would require derivative hardware designs to remain under the same license.

This is a valid option, but it is more restrictive than needed for OpenDuel at this stage.

## Consequences

### Positive

- Each type of asset uses a license suited to its purpose.
- Firmware remains easy to reuse and integrate.
- Documentation can be shared and adapted with attribution.
- Hardware and mechanical files have a dedicated open hardware license.
- The licensing strategy is explicit from the beginning.
- The project remains friendly to makers and contributors.

### Negative

- Multi-licensing is slightly more complex than using a single license.
- The repository must clearly document which license applies to which files.
- Contributors must understand that not every file has the same license.
- Additional license files and notices may be required.

## Notes

This decision does not grant permission to use official licensed assets from third-party franchises.

OpenDuel must remain an independent fan-made project and must not distribute official logos, card artwork, proprietary names, copyrighted illustrations or licensed assets.

This decision may be revisited if the project receives external contributions or if the hardware strategy changes significantly.