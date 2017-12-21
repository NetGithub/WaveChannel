#include "wave_trans_recv.h"
#include "transceiver/recv/wt_recv_link_layer.h"
#include "transceiver/recv/wt_recv_physical_layer.h"

int WaveTransRecvInit()
{
  if (WTRecvLinkLayerInit() != 0) {
    return -1;
  }
  if (WTRecvPhyLayerInit() != 0) {
    return -1;
  }
  return 0;
}

void WaveTransRecvExit()
{
  WTRecvPhyLayerExit();
  WTRecvLinkLayerExit();
}

void WaveTransRecvSetPcm(const RecvAudioType * pcm, int pcm_len)
{
  WTRecvPhyLayerSendPcm(pcm, pcm_len);
}

int WaveTransRecvGetContext(void * context, int context_len)
{
  return WTRecvLinkLayerGetData(context, context_len);
}