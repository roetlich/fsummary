# fsummary

[![linux build](https://github.com/roetlich/fsummary/actions/workflows/linux-build.yaml/badge.svg)](https://github.com/roetlich/fsummary/actions/workflows/linux-build.yaml) [![linux test](https://github.com/roetlich/fsummary/actions/workflows/linux-test.yaml/badge.svg)](https://github.com/roetlich/fsummary/actions/workflows/linux-test.yaml) [![macos build](https://github.com/roetlich/fsummary/actions/workflows/macos-build.yaml/badge.svg)](https://github.com/roetlich/fsummary/actions/workflows/macos-build.yaml) [![macos test](https://github.com/roetlich/fsummary/actions/workflows/macos-test.yaml/badge.svg)](https://github.com/roetlich/fsummary/actions/workflows/macos-test.yaml)

This is a project to compare scripting languages. It's also a usable CLI tool, that prints information about a file. Depending on the file extension it will use a script to get information about the file.

## Build

```sh
git clone https://github.com/roetlich/fsummary.git
make install dependencies
make build
./fsummay a_file_you_like.example

```

## Scripting languages

Currently the scripting langues are lua and yasl. My goal is to add more. If you have one to add, feel free to make a PR :)
