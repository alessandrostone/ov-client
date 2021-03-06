#ifndef OV_CLIENT_ORLANDOVIOLS
#define OV_CLIENT_ORLANDOVIOLS

#include "ov_types.h"
#include <thread>

class ov_client_orlandoviols_t : public ov_client_base_t {
public:
  ov_client_orlandoviols_t(ov_render_base_t& backend, const std::string& lobby);
  void start_service();
  void stop_service();
  bool download_file(const std::string& url, const std::string& dest);

private:
  void service();
  void device_init(std::string url, const std::string& device);
  std::string device_update(std::string url, const std::string& device,
                            std::string& hash);
  void report_error(std::string url, const std::string& device,
                    const std::string& msg);

  bool runservice;
  std::thread servicethread;
  std::string lobby;
};

#endif

/*
 * Local Variables:
 * mode: c++
 * compile-command: "make -C .."
 * End:
 */
