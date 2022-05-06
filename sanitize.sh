#!/bin/bash
rm -rf build
meson setup build -Db_sanitize=address
ninja -C build scan-build