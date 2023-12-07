#!/bin/bash

# Formatage du code Java selon le Google Java Style Guide
find . -name "*.java" -exec google-java-format -i {} \;
