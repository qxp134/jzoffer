## setup git pre commit hooks

The git pre commit hooks will (1) run clang-format (https://github.com/andrewseidl/githook-clang-format) (2) run cpplinter to check wither the code conforms Google Coding Style (https://github.com/google/styleguide).


- make sure `clang-format` and `python` installed
- run 
  ```bash
  cp githooks/* .git/hooks/ && cd .git/hooks && chmod +x pre-commit clang-format.hook cpplint.hook cpplint.py && cd -
  ```
