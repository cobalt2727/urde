#include "DataSpec/DNACommon/ATBL.hpp"

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <vector>

#include "DataSpec/DNACommon/DNACommon.hpp"
#include "DataSpec/DNACommon/PAK.hpp"

#include <athena/FileReader.hpp>
#include <athena/FileWriter.hpp>
#include <athena/YAMLDocReader.hpp>
#include <athena/YAMLDocWriter.hpp>

#include <fmt/format.h>

namespace DataSpec::DNAAudio {

bool ATBL::Extract(PAKEntryReadStream& rs, const hecl::ProjectPath& outPath) {
  uint32_t idxCount = rs.readUint32Big();
  athena::io::YAMLDocWriter w("ATBL");
  for (uint32_t i = 0; i < idxCount; ++i) {
    uint16_t idx = rs.readUint16Big();
    if (idx == 0xffff)
      continue;
    w.writeUint16(fmt::format(FMT_STRING("0x{:04X}"), i), idx);
  }

  athena::io::FileWriter fw(outPath.getAbsolutePath());
  w.finish(&fw);

  return true;
}

bool ATBL::Cook(const hecl::ProjectPath& inPath, const hecl::ProjectPath& outPath) {
  athena::io::FileReader r(inPath.getAbsolutePath());
  if (r.hasError())
    return false;

  athena::io::YAMLDocReader dr;
  if (!dr.parse(&r))
    return false;

  unsigned long maxI = 0;
  for (const auto& pair : dr.getRootNode()->m_mapChildren) {
    unsigned long i = strtoul(pair.first.c_str(), nullptr, 0);
    maxI = std::max(maxI, i);
  }

  std::vector<uint16_t> vecOut(maxI + 1, 0xffff);
  for (const auto& pair : dr.getRootNode()->m_mapChildren) {
    unsigned long i = strtoul(pair.first.c_str(), nullptr, 0);
    vecOut[i] = hecl::SBig(uint16_t(strtoul(pair.second->m_scalarString.c_str(), nullptr, 0)));
  }

  athena::io::FileWriter w(outPath.getAbsolutePath());
  if (w.hasError())
    return false;
  w.writeUint32Big(uint32_t(vecOut.size()));
  w.writeBytes(vecOut.data(), vecOut.size() * 2);

  return true;
}

} // namespace DataSpec::DNAAudio
