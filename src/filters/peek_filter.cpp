/**
 * Copyright 2019 w1d3m0d3
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include "filters/peek_filter.hpp"

visualize::peek_filter::peek_filter(size_t data_size, double gravity) :
    peeks(std::make_unique<double[]>(data_size)),
    data_size(data_size),
    gravity(gravity / 1000) {}

void visualize::peek_filter::do_apply(double *data) {
    for (size_t i = 0; i < data_size; i++) {
        auto &peek = peeks[i];
        auto &curr = data[i];
        peek = std::max(curr, peek);
        curr = (curr + peek) / 2;

        if (peek >= gravity) {
            peek -= gravity;
        } else {
            peek = 0;
        }
    }
}
