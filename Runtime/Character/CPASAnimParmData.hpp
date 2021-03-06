#pragma once

#include "Runtime/RetroTypes.hpp"
#include "Runtime/rstl.hpp"
#include "Runtime/Character/CPASAnimParm.hpp"

namespace urde {
class CPASAnimParmData {
  s32 x0_stateId;
  rstl::reserved_vector<CPASAnimParm, 8> x4_parms;

public:
  CPASAnimParmData() = default;

  explicit CPASAnimParmData(s32 stateId, const CPASAnimParm& parm1 = CPASAnimParm::NoParameter(),
                            const CPASAnimParm& parm2 = CPASAnimParm::NoParameter(),
                            const CPASAnimParm& parm3 = CPASAnimParm::NoParameter(),
                            const CPASAnimParm& parm4 = CPASAnimParm::NoParameter(),
                            const CPASAnimParm& parm5 = CPASAnimParm::NoParameter(),
                            const CPASAnimParm& parm6 = CPASAnimParm::NoParameter(),
                            const CPASAnimParm& parm7 = CPASAnimParm::NoParameter(),
                            const CPASAnimParm& parm8 = CPASAnimParm::NoParameter());

  s32 GetStateId() const { return x0_stateId; }
  const rstl::reserved_vector<CPASAnimParm, 8>& GetAnimParmData() const { return x4_parms; }

  static auto NoParameters(s32 stateId) { return CPASAnimParmData(stateId); }
};
} // namespace urde
