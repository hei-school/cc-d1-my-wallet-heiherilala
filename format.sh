#!/bin/bash

# Formatage du code JavaScript selon le Google JavaScript Style Guide
find . -name "*.js" -exec prettier --write {} \;
