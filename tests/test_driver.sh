#!/bin/sh

cd .. && \
./third_party/smart-build/src/smart-build.sh \
  --clean-all \
  --build-type-release \
  --make-tests && \
./eight-puzzle-tests --no-skip

