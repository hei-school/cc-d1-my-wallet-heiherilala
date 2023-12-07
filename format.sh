#!/bin/bash

# Formatage du code Python selon PEP 8
find . -name "*.py" -exec autopep8 --in-place --aggressive --aggressive {} \;
