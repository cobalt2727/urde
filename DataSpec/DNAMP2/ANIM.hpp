#pragma once

#include "DNAMP2.hpp"
#include "DataSpec/DNACommon/ANIM.hpp"
#include "DataSpec/DNACommon/RigInverter.hpp"
#include "CINF.hpp"
#include "DataSpec/DNACommon/ANCS.hpp"

namespace DataSpec::DNAMP2 {

struct ANIM : BigDNA {
  AT_DECL_EXPLICIT_DNA

  struct IANIM : BigDNAV {
    Delete expl;
    atUint32 m_version;
    IANIM(atUint32 version) : m_version(version) {}

    std::vector<std::pair<atUint32, std::tuple<bool, bool, bool>>> bones;
    std::vector<atUint32> frames;
    std::vector<DNAANIM::Channel> channels;
    std::vector<std::vector<DNAANIM::Value>> chanKeys;
    float mainInterval = 0.0;
    bool looping = false;

    void sendANIMToBlender(hecl::blender::PyOutStream&, const DNAANIM::RigInverter<CINF>& rig) const;
  };

  struct ANIM0 : IANIM {
    AT_DECL_EXPLICIT_DNAV
    ANIM0() : IANIM(0) {}

    struct Header : BigDNA {
      AT_DECL_DNA
      Value<float> duration;
      Value<atUint32> unk0;
      Value<float> interval;
      Value<atUint32> unk1;
      Value<atUint32> keyCount;
      Value<atUint32> unk2;
      Value<atUint32> boneSlotCount;
    };
  };

  struct ANIM2 : IANIM {
    AT_DECL_EXPLICIT_DNAV
    ANIM2() : IANIM(2) {}

    struct Header : BigDNA {
      AT_DECL_DNA
      Value<atUint32> scratchSize;
      Value<atUint16> unk1;
      Value<float> duration;
      Value<float> interval;
      Value<atUint32> rootBoneId = 3;
      Value<atUint32> looping = 0;
      Value<atUint32> rotDiv;
      Value<float> translationMult;
      Value<float> scaleMult;
      Value<atUint32> boneChannelCount;
      Value<atUint32> unk3 = 1;
      Value<atUint32> keyBitmapBitCount;
    };

    struct ChannelDesc : BigDNA {
      Delete expl;
      Value<atUint8> id = 0;
      Value<atUint16> keyCount1 = 0;
      Value<atInt16> initRX = 0;
      Value<atUint8> qRX = 0;
      Value<atInt16> initRY = 0;
      Value<atUint8> qRY = 0;
      Value<atInt16> initRZ = 0;
      Value<atUint8> qRZ = 0;
      Value<atUint16> keyCount2 = 0;
      Value<atInt16> initTX = 0;
      Value<atUint8> qTX = 0;
      Value<atInt16> initTY = 0;
      Value<atUint8> qTY = 0;
      Value<atInt16> initTZ = 0;
      Value<atUint8> qTZ = 0;
      Value<atUint16> keyCount3 = 0;
      Value<atInt16> initSX = 0;
      Value<atUint8> qSX = 0;
      Value<atInt16> initSY = 0;
      Value<atUint8> qSY = 0;
      Value<atInt16> initSZ = 0;
      Value<atUint8> qSZ = 0;

      void read(athena::io::IStreamReader& reader) {
        id = reader.readUByte();
        keyCount1 = reader.readUint16Big();
        if (keyCount1) {
          initRX = reader.readInt16Big();
          qRX = reader.readUByte();
          initRY = reader.readInt16Big();
          qRY = reader.readUByte();
          initRZ = reader.readInt16Big();
          qRZ = reader.readUByte();
        }
        keyCount2 = reader.readUint16Big();
        if (keyCount2) {
          initTX = reader.readInt16Big();
          qTX = reader.readUByte();
          initTY = reader.readInt16Big();
          qTY = reader.readUByte();
          initTZ = reader.readInt16Big();
          qTZ = reader.readUByte();
        }
        keyCount3 = reader.readUint16Big();
        if (keyCount3) {
          initSX = reader.readInt16Big();
          qSX = reader.readUByte();
          initSY = reader.readInt16Big();
          qSY = reader.readUByte();
          initSZ = reader.readInt16Big();
          qSZ = reader.readUByte();
        }
      }
      void write(athena::io::IStreamWriter& writer) const {
        writer.writeUByte(id);
        writer.writeUint16Big(keyCount1);
        if (keyCount1) {
          writer.writeInt16Big(initRX);
          writer.writeUByte(qRX);
          writer.writeInt16Big(initRY);
          writer.writeUByte(qRY);
          writer.writeInt16Big(initRZ);
          writer.writeUByte(qRZ);
        }
        writer.writeUint16Big(keyCount2);
        if (keyCount2) {
          writer.writeInt16Big(initTX);
          writer.writeUByte(qTX);
          writer.writeInt16Big(initTY);
          writer.writeUByte(qTY);
          writer.writeInt16Big(initTZ);
          writer.writeUByte(qTZ);
        }
        writer.writeUint16Big(keyCount3);
        if (keyCount3) {
          writer.writeInt16Big(initSX);
          writer.writeUByte(qSX);
          writer.writeInt16Big(initSY);
          writer.writeUByte(qSY);
          writer.writeInt16Big(initSZ);
          writer.writeUByte(qSZ);
        }
      }
      size_t binarySize(size_t __isz) const {
        __isz += 7;
        if (keyCount1)
          __isz += 9;
        if (keyCount2)
          __isz += 9;
        if (keyCount3)
          __isz += 9;
        return __isz;
      }
    };
  };

  std::unique_ptr<IANIM> m_anim;

  void sendANIMToBlender(hecl::blender::PyOutStream& os, const DNAANIM::RigInverter<CINF>& rig, bool) const {
    m_anim->sendANIMToBlender(os, rig);
  }

  void extractEVNT(const DNAANCS::AnimationResInfo<UniqueID32>& animInfo, const hecl::ProjectPath& outPath,
                   PAKRouter<PAKBridge>& pakRouter, bool force) const {}
};

} // namespace DataSpec::DNAMP2
