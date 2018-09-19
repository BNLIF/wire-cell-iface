/** Provide more than one way to talk about channels and wires
 */

#ifndef WIRECELLIFACE_ICHANNELMAPPER
#define WIRECELLIFACE_ICHANNELMAPPER

#include "WireCellUtil/Waveform.h"
#include "WireCellUtil/IComponent.h"

namespace WireCell {

    class IChannelMapper : public IComponent<IChannelMapper>  {
    public:
        virtual IChannelMapper() {}

        // Various numbers related to a channel.
        struct ChanInfo {
            // A 0-based index that counts channels in one plane and
            // alone one or both faces.

            int anode_plane_loop;


            int wire;               // between 0 and nwire_{u,v,w,}-1 depending on plane
            int plane;              // 0,1,2
            OspChan(int c=-1, int w=-1, int p=-1) : channel(c), wire(w), plane(p) {}
            bool operator<(const OspChan& lhs) const {
                return channel < lhs.channel;
            }
        };

      typedef std::map<int,OspChan> osp_channel_map_t;
      osp_channel_map_t m_channel_map; // indexed by WCT channel ident, not OSP channel!
      template <typename I>
      struct iter_pair : std::pair<I,I> {
        using std::pair<I, I>::pair;
        I begin() { return this->first; }
        I end() { return this->second; }
      };
      typedef iter_pair<osp_channel_map_t::iterator> channel_range_t;
      // return per-plane range for easy iterating
      channel_range_t m_channel_range[3];
      // fixme: this should probably move into IAnodePlane.

        
    };
}

#endif
