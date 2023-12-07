#!/bin/bash

# Formatage du code C++ selon le Google C++ Style Guide
find . -name "*.cpp" -o -name "*.h" -exec clang-format -i {} \;

## Conventions de Codage (Coding Standards) et Formatage du Code

Nous suivons le [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

### Comment formater le code

Le code C++ est automatiquement formaté en utilisant `clang-format`. Assurez-vous de l'avoir installé.

Pour formater le code manuellement, exécutez le script suivant :

```bash
./format.sh