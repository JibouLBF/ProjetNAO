/*
 * Copyright (c) 2012 Aldebaran Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */
#include <iostream>

#include "motion.h"
#include "head.h"

int main()
{
  std::cout << "Hello, world" << std::endl;
   Motion* bm = new Head();
   bm->action();
  return 0;
}
