// Copyright 2016, Tobias Hermann.
// https://github.com/Dobiasd/frugally-deep
// Distributed under the MIT License.
// (See accompanying LICENSE file or at
//  https://opensource.org/licenses/MIT)

#pragma once

#include "frugally_deep/layers/layer.h"

namespace fd
{

// Converts a volume into single column volume (size3d(1, n, 1)).
class flatten_layer : public layer
{
public:
    explicit flatten_layer(const size3d& size_in) :
            layer(size_in, size3d(1, size_in.volume(), 1))
    {
    }
    std::size_t param_count() const override
    {
        return 0;
    }
    float_vec get_params() const override
    {
        return {};
    }
    void set_params(const float_vec& params) override
    {
        assert(params.size() == param_count());
    }
protected:
    matrix3d forward_pass_impl(const matrix3d& input) const override
    {
        return reshape_matrix3d(input, output_size());
    }
};

} // namespace fd