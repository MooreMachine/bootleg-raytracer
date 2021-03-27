#!/bin/bash

VERSION=$(cat README.md | grep "Version" | awk '{print $2}')
OLD_VERSION=$VERSION

CHANGED_DOCKER=$(git diff --name-only Dockerfile)
CHANGED_README_VERSION=$(git diff README.md | grep +Version)

# if your Dockerfile changed but your README.md version number hasn't been updated
if [ ! -z ${CHANGED_DOCKER} ] && [ -z ${CHANGED_README_VERSION} ]
then
    printf 'Please consider updating the version number.\nCurrent version: %s\n' "$VERSION"
    read -p "New version: " NEW_VERSION
    if [ ! -z ${NEW_VERSION} ]
    then
        if [[ ! $NEW_VERSION =~ [0-9]+\.[0-9]+\.[0-9] ]]
        then
            "Please provide a version number in the form of MAJOR.MINOR.PATCH"
            exit 1
        fi
    else
        echo "Please provide a version number"
        exit 1
    fi
    VERSION=$NEW_VERSION
fi

docker build --tag mooremachine/easyubuntu:$VERSION .

if [ $? -ne 0 ]
then
    echo "docker build failed!"
    exit 1
fi

sed -i '' 's/Version: '"$OLD_VERSION"'/Version: '"$VERSION"'/g' README.md
