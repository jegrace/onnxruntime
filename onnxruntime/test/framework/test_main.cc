// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "core/session/environment.h"
#include "gtest/gtest.h"
#include "test/test_environment.h"
#include "core/session/onnxruntime_cxx_api.h"

int main(int argc, char** argv) {
  int status = 0;

  ORT_TRY {
    onnxruntime::test::TestEnvironment test_environment{argc, argv};

    status = RUN_ALL_TESTS();
  }
#ifndef ORT_NO_EXCEPTIONS
  catch (const std::exception& ex) {
    std::cerr << ex.what();
    status = -1;
  }
#endif

  return status;
}
