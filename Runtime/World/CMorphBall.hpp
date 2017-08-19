#ifndef __URDE_CMORPHBALL_HPP__
#define __URDE_CMORPHBALL_HPP__

#include "World/CActor.hpp"
#include "World/ScriptObjectSupport.hpp"
#include "zeus/CVector3f.hpp"
#include "Collision/CCollidableSphere.hpp"
#include "RetroTypes.hpp"

namespace urde
{
class CActorLights;
class CPlayer;
class CDamageInfo;
class CFinalInput;
class CScriptWater;
class CStateManager;
class CMorphBallShadow;

class CMorphBall
{
public:
    enum class EBallBoostState
    {
        Zero
    };

    enum class ESpiderBallState
    {
        Zero
    };

    enum class EBombJumpState
    {
        Zero,
        One
    };
private:
    CPlayer& x0_player;
    std::unique_ptr<CModelData> x58_ballModel;
    u32 x5c_ballModelShader = 0;
    std::unique_ptr<CModelData> x60_spiderBallGlassModel;
    u32 x64_spiderBallGlassModelShader = 0;
    std::unique_ptr<CModelData> x68_lowPolyBallModel;
    u32 x6c_lowPolyBallModelShader = 0;
    std::unique_ptr<CModelData> x70_frozenBallModel;
    u32 x74_frozenBallModelShader = 0;
    u32 x187c_ = 0;
    float x1914_ = 0.f;
    float x1918_ = 0.f;
    float x191c_damageTimer = 0.f;
    bool x1920_ = false;
    zeus::CTransform x1924_;
    bool x1954_isProjectile = false;
    u32 x195c_ = false;
    u32 x1960_ = false;
    u32 x1964_ = false;
    u32 x19dc_ = false;
    union
    {
        struct
        {
            bool x1de4_25 : 1;
        };
        u32 _dummy = 0;
    };
    float x1DE8_boostTime = 0.f;
    EBombJumpState x1e40_bombJumpState = EBombJumpState::Zero;
    CMorphBallShadow* x1e50_shadow = nullptr;

public:
    CMorphBall(CPlayer& player, float);
    void AcceptScriptMsg(EScriptObjectMessage msg, TUniqueId sender, CStateManager& mgr);
    ESpiderBallState GetSpiderBallState() const { return ESpiderBallState::Zero; }
    bool InSpiderMode() const { return false; }
    zeus::CVector3f GetBallContactSurfaceNormal() const { return {}; }
    void GetModel() const {}
    const CCollidableSphere* GetCollidableSphere() const { return nullptr; }
    bool IsProjectile() const { return x1954_isProjectile; }
    void GetBallContactMeterials() const {}
    void GetWallBumpCounter() const {}
    void GetBoostChargeTimer() const {}
    bool IsBoosting() const { return false; }
    float GetBallRadius() const { return 0.f; }
    float GetBallTouchRadius() const { return 0.f; }
    void ForwardInput(const CFinalInput&) const {}
    void ComputeBallMovement(const CFinalInput&, CStateManager&, float) {}
    bool IsMovementAllowed() const { return false; }
    void UpdateSpiderBall(const CFinalInput&, CStateManager&, float) {}
    void ApplySpiderBallSwingingForces(const CFinalInput&, CStateManager&, float) {}
    void ApplySpiderBallRollForces(const CFinalInput&, CStateManager&, float) {}
    void CalculateSpiderBallAttractionSurfaceForces(const CFinalInput&, CStateManager&,
                                                    const zeus::CTransform&) {}
    void CheckForSwitchToSpiderBallSwinging(CStateManager&) {}
    void FindClosestSpiderBallWaypoint(CStateManager&, const zeus::CVector3f&, zeus::CVector3f&,
                                       zeus::CVector3f&, zeus::CVector3f&, float&, zeus::CVector3f&, bool&,
                                       zeus::CTransform&) const {}
    void SetSpiderBallSwingingState(bool) {}
    void GetSpiderBallControllerMovement(const CFinalInput&, bool, bool) {}
    void ResetSpiderBallSwingControllerMovementTimer() {}
    void UpdateSpiderBallSwingControllerMovementTimer(float, float) {}
    float GetSpiderBallSwingControllerMovementScalar() const { return 0.f; }
    void CreateSpiderBallParticles(const zeus::CVector3f&, const zeus::CVector3f&) {}
    void ComputeMarioMovement(const CFinalInput&, CStateManager&, float) {}
    void SetSpiderBallState(ESpiderBallState) {}
    void GetSwooshToWorld() const {}
    zeus::CTransform GetBallToWorld() const { return {}; }
    void CalculateSurfaceToWorld(const zeus::CVector3f&, const zeus::CVector3f&, const zeus::CVector3f&) const {}
    void CalculateBallContactInfo(zeus::CVector3f&, zeus::CVector3f&) const {}
    void BallTurnInput(const CFinalInput&) const {}
    void UpdateBallDynamics(CStateManager&, float) {}
    void SwitchToMarble() {}
    void SwitchToTire() {}
    void Update(float, CStateManager&) {}
    void UpdateScriptMessage(EScriptObjectMessage, TUniqueId, CStateManager&) {}
    void DeleteLight(CStateManager&) {}
    void SetBallLightActive(CStateManager&, bool) {}
    void EnterMorphBallState(CStateManager&) {}
    void LeaveMorphBallState(CStateManager&) {}
    void UpdateEffects(float, CStateManager&) {}
    void ComputeBoostBallMovement(const CFinalInput&, const CStateManager&, float) {}
    void EnterBoosting() {}
    void LeaveBoosting() {}
    void CancelBoosting() {}
    void UpdateMarbleDynamics(CStateManager&, float, const zeus::CVector3f&) {}
    void ApplyFriction(float) {}
    void DampLinearAndAngularVelocities(float, float) {}
    zeus::CTransform GetPrimitiveTransform() const { return {}; }
    void DrawCollisionPrimitive() const {}
    void GetMinimumAlignmentSpeed() const {}
    void PreRender(CStateManager&, const zeus::CFrustum&) {}
    void Render(const CStateManager&, const CActorLights*) const {}
    void ResetMorphBallTransitionFlash() {}
    void UpdateMorphBallTransitionFlash(float) {}
    void RenderMorphBallTransitionFlash(const CStateManager&) const {}
    bool IsMorphBallTransitionFlashValid() const { return x19dc_ != 0; }
    void RenderDamageEffects(const CStateManager&, const zeus::CTransform&) const {}
    void UpdateHalfPipeStatus(CStateManager&, float) {}
    bool GetIsInHalfPipeMode() const { return false; }
    void SetIsInHalfPipeMode(bool) {}
    void GetIsInHalfPipeModeInAir() const {}
    void SetIsInHalfPipeModeInAir(bool) {}
    void GetTouchedHalfPipeRecently() const {}
    void SetTouchedHalfPipeRecently(bool) {}
    void DisableHalfPipeStatus() {}
    void BallCloseToCollision(const CStateManager&, float) const {}
    void CollidedWith(TUniqueId, const CCollisionInfoList&, CStateManager&) {}
    bool IsInFrustum(const zeus::CFrustum&) const { return false; }
    void ComputeLiftForces(const zeus::CVector3f&, const zeus::CVector3f&, const CStateManager&) {}
    void CalculateSurfaceFriction() const {}
    void ApplyGravity(CStateManager&) {}
    void SpinToSpeed(float, zeus::CVector3f, float) {}
    void ComputeMaxSpeed() const {}
    void Touch(CActor&, CStateManager&) {}
    bool IsClimbable(const CCollisionInfo&) const { return false; }
    void FluidFXThink(CActor::EFluidState, CScriptWater&, CStateManager&) {}
    void GetMorphBallModel(const std::string&, float) {}
    void LoadMorphBallModel(CStateManager& mgr) {}
    void AddSpiderBallElectricalEffect() {}
    void UpdateSpiderBallElectricalEffect() {}
    void RenderSpiderBallElectricalEffect() const {}
    void RenderEnergyDrainEffects(const CStateManager&) const {}
    void TouchModel(const CStateManager&) const {}
    void SetAsProjectile(const CDamageInfo&, const CDamageInfo&) {}
    EBallBoostState GetBallBoostState() const { return EBallBoostState::Zero; }
    void SetBallBoostState(EBallBoostState) {}
    EBombJumpState GetBombJumpState() const { return x1e40_bombJumpState; }
    void LoadAnimationTokens(const std::string&) {}
    void TakeDamage(float) {}
    void DrawBallShadow(const CStateManager& mgr);
    void DeleteBallShadow();
    void CreateBallShadow();
    void RenderToShadowTex(CStateManager& mgr);
    void StartLandingSfx() {}
    bool GetX187c() const { return x187c_ != 0; }
    void SetDamageTimer(float t) { x191c_damageTimer = t; }
    void Stop() {}
    void StopSounds() {}
    void ActorAttached() {}
    CModelData& GetMorphballModelData() const { return *x58_ballModel; }
    u32 GetMorphballModelShader() const { return x5c_ballModelShader; }
    bool GetX1DE4_25() const { return x1de4_25; }
    void SetX1DE4_25(bool b) { x1de4_25 = b; }
};

}

#endif // __URDE_CMORPHBALL_HPP__
