#ifdef CHANNEL_MKL

#ifndef CHANNEL_AWGN_MKL_LLR_HPP_
#define CHANNEL_AWGN_MKL_LLR_HPP_

#include <mkl_vsl.h>

#include "../../../Channel.hpp"

namespace aff3ct
{
namespace module
{
template <typename R = float>
class Channel_AWGN_MKL_LLR : public Channel<R>
{
private:
	VSLStreamStatePtr stream_state;

public:
	Channel_AWGN_MKL_LLR(const int N, const R& sigma, const int seed = 0, const int n_frames = 1, 
	                     const std::string name = "Channel_AWGN_MKL_LLR");
	virtual ~Channel_AWGN_MKL_LLR();

	virtual void add_noise(const R *X_N, R *Y_N); using Channel<R>::add_noise;
};
}
}

#endif // CHANNEL_AWGN_MKL_LLR_HPP_

#endif
