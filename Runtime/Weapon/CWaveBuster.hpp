#pragma once

#include <memory>

#include "Runtime/CRandom16.hpp"
#include "Runtime/RetroTypes.hpp"
#include "Runtime/Weapon/CGameProjectile.hpp"

#include <zeus/CTransform.hpp>
#include <zeus/CVector3f.hpp>

namespace urde {

class CWaveBuster : public CGameProjectile {
  zeus::CTransform x2e8_originalXf;
  zeus::CVector3f x318_;
  zeus::CVector3f x324_;
  zeus::CVector3f x330_;
  zeus::CVector3f x33c_;
  zeus::CVector3f x348_targetPoint;
  TCachedToken<CSwooshDescription> x354_busterSwoosh1;
  TCachedToken<CSwooshDescription> x360_busterSwoosh2;
  TCachedToken<CGenDescription> x36c_busterSparks;
  TCachedToken<CGenDescription> x378_busterLight;
  std::unique_ptr<CParticleSwoosh> x384_busterSwoosh1Gen;
  std::unique_ptr<CParticleSwoosh> x388_busterSwoosh2Gen;
  std::unique_ptr<CElementGen> x38c_busterSparksGen;
  std::unique_ptr<CElementGen> x390_busterLightGen;
  CRandom16 x394_rand{99};
  float x398_ = 2.f*M_PIF;
  float x39c_ = 0.5f;
  float x3a0_ = 0.5f;
  float x3a4_ = 0.f;
  float x3a8_ = 0.f;
  float x3ac_ = 0.f;
  float x3b0_ = 0.f;
  float x3b4_ = 0.f;
  float x3b8_ = 0.f;
  float x3bc_ = 0.f;
  float x3c0_ = 0.f;
  float x3c4_ = 0.f;
  float x3c8_ = 0.f;
  u32 x3cc_ = 0;
  bool x3d0_24_firing : 1 = true;
  bool x3d0_25_ : 1 = true;
  bool x3d0_26_ : 1 = false;
  bool x3d0_27_ : 1 = false;
  bool x3d0_28_ : 1 = true;

  void sub_801be350();
  void sub_801be5c0();
  CRayCastResult sub_801be010(TUniqueId uid, const zeus::CVector3f& p1, const zeus::CVector3f& p2, CStateManager& mgr);
  void sub_801bf598(float dt, CStateManager& mgr);
  void UpdateTargetDamage(float dt, CStateManager& mgr);
  bool UpdateTargetSeek(float dt, CStateManager& mgr);
  float GetViewAngleToTarget(zeus::CVector3f& p1, const CActor& act);
public:
  CWaveBuster(const TToken<CWeaponDescription>& desc, EWeaponType type, const zeus::CTransform& xf,
              EMaterialTypes matType, const CDamageInfo& dInfo, TUniqueId uid, TAreaId aid, TUniqueId owner,
              TUniqueId homingTarget, EProjectileAttrib attrib);
  void Accept(IVisitor& visitor) override;
  void Think(float dt, CStateManager& mgr) override;
  void AcceptScriptMsg(EScriptObjectMessage msg, TUniqueId sender, CStateManager& mgr) override;
  void AddToRenderer(const zeus::CFrustum& frustum, CStateManager& mgr) override;
  void Render(CStateManager& mgr) override;
  std::optional<zeus::CAABox> GetTouchBounds() const override;
  bool IsFiring() const { return x3d0_24_firing; }
  void UpdateFx(const zeus::CTransform& xf, float dt, CStateManager& mgr);
  void ResetBeam(bool deactivate);
  void SetNewTarget(TUniqueId id, CStateManager& mgr);
};

} // namespace urde
