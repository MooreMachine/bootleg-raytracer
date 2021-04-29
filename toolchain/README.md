# Easy Ubuntu Toolchain

This repository comes with a [Dockerfile](Dockerfile) to build a container for our toolchain. The toolchain includes everything necessary to build the application, plus some extra tools.

## Building the container

To build the container, run the [execute_tests.sh](../execute_tests.sh) script. If there are uncommitted changes to the [Dockerfile](Dockerfile), the script will ask you if you want to provide a new version number. If you do, it will automatically update the version number in this [README.md](README.md) file. The idea is that whenever we make changes to the container, and if we intend to push them to [hub.docker.com](https://hub.docker.com/repository/docker/mooremachine/easyubuntu), we should bump up the version number.

We try to use [semantic versioning 2.0.0](https://semver.org/spec/v2.0.0.html) to keep track of new versions of our toolchain. Try to follow these rules as you modify our toolchain. Document any official changes in the [CHANGELOG.md](CHANGELOG.md) file.

To push a new image to [hub.docker.com](https://hub.docker.com/repository/docker/mooremachine/easyubuntu), you'll need to be added as a collaborator. Once you are added, simply run `docker push mooremachine/easyubuntu:<tag>`.

## Running the container

There are two options to run the container: interactive and detached mode. To run in interactive mode use the [run_interactive_container.sh](../run_interactive_container.sh) script. The other script, [execute_tests.sh](../execute_tests.sh), provides an easy way to run the container in detached mode and automatically run our build and unit tests. This script is the same used by our GitHub Actions workflow.

## About

Version: 0.2.3
