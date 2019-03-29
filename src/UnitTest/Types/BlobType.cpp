// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#include "TestUtility/UnitTest.h"

#include "Open3D/Types/Blob.h"

#include <Eigen/Geometry>

#include <iostream>
using namespace std;
using namespace unit_test;

// ----------------------------------------------------------------------------
// Make sure the types are PODs.
// ----------------------------------------------------------------------------
TEST(BlobType, is_POD) {
    EXPECT_FALSE(is_pod<open3d::Blob2i>());
    EXPECT_FALSE(is_pod<open3d::Blob3i>());
    EXPECT_FALSE(is_pod<open3d::Blob3d>());
}

// ----------------------------------------------------------------------------
// Default constructor.
// ----------------------------------------------------------------------------
TEST(BlobType, Default_constructor) {
    open3d::Blob<Eigen::Vector3d, double>::Type b3d;

    EXPECT_EQ(b3d.num_elements, 0);
    EXPECT_EQ(b3d.device_id, open3d::cuda::DeviceID::CPU);
    EXPECT_EQ(b3d.h_data.size(), 0);
    EXPECT_TRUE(NULL == b3d.d_data);
    EXPECT_EQ(b3d.size(), 0);
}
