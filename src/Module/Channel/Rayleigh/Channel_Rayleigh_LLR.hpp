#ifndef CHANNEL_RAYLEIGH_LLR_HPP_
#define CHANNEL_RAYLEIGH_LLR_HPP_

#include <random>

#include "../Channel.hpp"

namespace aff3ct
{
namespace module
{
template <typename R = float>
class Channel_Rayleigh_LLR : public Channel<R> // flat Rayleigh fading channel
{
private:
	const bool complex;

	std::random_device          rd;
	std::mt19937                rd_engine;
	std::normal_distribution<R> normal_dist_n;
	std::normal_distribution<R> normal_dist_h;

public:
	Channel_Rayleigh_LLR(const int N, const R& sigma, const bool complex, const int seed = 0, const int n_frames = 1,
	                     const std::string name = "Channel_Rayleigh_LLR");
	virtual ~Channel_Rayleigh_LLR();

	void set_sigma(const R sigma);

	virtual void add_noise(const R *X_N, R *Y_N, R *H_N); using Channel<R>::add_noise;
};
}
}

#endif /* CHANNEL_RAYLEIGH_LLR_HPP_ */
