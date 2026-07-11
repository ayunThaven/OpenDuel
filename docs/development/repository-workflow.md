# Repository Workflow

This document describes the development workflow used by OpenDuel.

The goal is to keep the project clean, understandable and easy to contribute to, even during early prototyping.

## 1. Main branch

The `main` branch is protected.

Direct pushes to `main` are not allowed. Every change must go through a dedicated branch and a pull request.

This ensures that all changes are visible, reviewable and documented before they become part of the stable project history.

## 2. Branch naming

Branches should use a short prefix describing the type of work.

Recommended prefixes:

- `docs/` for documentation changes;
- `feature/` for new features;
- `fix/` for bug fixes;
- `chore/` for maintenance tasks;
- `refactor/` for code restructuring without behavior changes;
- `hardware/` for electronics-related changes;
- `mechanical/` for CAD, STL or 3D-printing changes.

Examples:

- `docs/project-charter`
- `docs/repository-workflow`
- `feature/wokwi-prototype`
- `feature/platformio-setup`
- `hardware/initial-bom`
- `mechanical/card-zone-module`

## 3. Issues

Issues are used for meaningful tasks, bugs, ideas and feature planning.

An issue should describe a clear objective, not a tiny implementation detail.

Good examples:

- Add Wokwi v0.1 prototype documentation
- Define the initial firmware architecture
- Add support for WS2812B LED zones
- Document the first hardware BOM

Avoid creating issues for very small changes such as renaming a local variable or fixing a typo, unless the typo is part of a larger documentation cleanup.

## 4. Pull requests

Every change should be proposed through a pull request.

A pull request should explain:

- what changed;
- why it changed;
- what files or areas are affected;
- whether there are follow-up tasks.

Pull requests should stay focused. A documentation update, a firmware refactor and a hardware BOM update should usually be separate pull requests.

## 5. Commit messages

OpenDuel uses a simple Conventional Commits style.

Common prefixes:

- `docs:` documentation changes;
- `feat:` new feature;
- `fix:` bug fix;
- `chore:` maintenance or setup;
- `refactor:` code restructuring without behavior changes;
- `test:` tests;
- `build:` build system or dependency changes.

Examples:

- `docs: add repository workflow`
- `feat: add duel state model`
- `fix: clamp life points to zero`
- `chore: initialize PlatformIO project`
- `refactor: extract display manager`

## 6. Pull request merging

For small and focused pull requests, `Squash and merge` is preferred.

This keeps the `main` history clean while allowing several small commits during development.

The final squash commit message should be clear and follow the same commit message style.

Example:

`docs: add repository workflow`

## 7. Local workflow

Typical workflow:

`issue → branch → commit(s) → pull request → merge`

Example workflow:

1. Update the local `main` branch:

   `git switch main`

   `git pull origin main`

2. Create a dedicated branch:

   `git switch -c docs/repository-workflow`

3. Add and commit the changes:

   `git add docs/development/repository-workflow.md`

   `git commit -m "docs: add repository workflow"`

4. Push the branch:

   `git push origin docs/repository-workflow`

5. Open a pull request from `docs/repository-workflow` to `main`.

After the pull request is merged:

1. Return to `main`:

   `git switch main`

2. Pull the latest changes:

   `git pull origin main`

3. Delete the local branch:

   `git branch -d docs/repository-workflow`

## 8. Force pushing

Force pushing should be avoided on shared branches.

For personal pull request branches, `git push --force-with-lease` may be used after an amend or rebase.

Use:

`git push --force-with-lease origin branch-name`

Avoid:

`git push --force`

## 9. Documentation as product

Documentation is considered part of the project, not an afterthought.

Architecture decisions, hardware choices, firmware structure and assembly steps should be documented as the project evolves.

This is especially important because OpenDuel aims to be reproducible by other makers.

## 10. Future improvements

The workflow may evolve later with:

- issue templates;
- pull request templates;
- GitHub Actions;
- PlatformIO build checks;
- markdown linting;
- automated formatting;
- release tags.
