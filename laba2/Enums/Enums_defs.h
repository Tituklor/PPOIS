#ifndef ENUMS_DEFS_H
#define ENUMS_DEFS_H

#include <string>

enum class ProductMaterial
{
    RubberMaterial,
    EVAMaterial,
    PlasticMaterial,
    PVCMaterial,
    LeatherMaterial,
    CottonMaterial,
    PolyesterMaterial,
    SpandexMaterial,
    MicrofiberMaterial,
    BambooMaterial,
    SteelMaterial,
    WoodMaterial,
    TextileMaterial,
    FoamMaterial,
    SyntheticMaterial,
    MeshMaterial,
    NylonMaterial,
    SiliconeMaterial,
    LatexMaterial,
    LycraMaterial
};

enum class ProductSize
{
    SizeXS,
    SizeS,
    SizeM,
    SizeL,
    SizeXL,
    SizeXXL,
    SizeEU38,
    SizeEU39,
    SizeEU40,
    SizeEU41,
    SizeEU42,
    SizeUniversal,
    SizeLarge,
    SizeChild
};

enum class BallCategory
{
    CategoryFitball,
    CategoryMedball,
    CategoryPilates,
    CategoryYoga,
    CategoryExercise
};

enum class GripType
{
    GripFoam,
    GripPlastic,
    GripWood,
    GripRubber
};

enum class ItemColor
{
    ColorBlack,
    ColorWhite,
    ColorRed,
    ColorBlue,
    ColorGreen,
    ColorNeonGreen,
    ColorGray,
    ColorPink
};

enum class ResistanceLevel
{
    LevelHigh,
    LevelMedium,
    LevelLow
};

enum class StretchLevel
{
    StretchHigh,
    StretchMedium,
    StretchLow
};

enum class LensShade
{
    ShadeClear,
    ShadeBlue,
    ShadeMirrored,
    ShadeSmoke,
    ShadeYellow,
    ShadePink,
    ShadeClubBranded
};

enum class GoggleFit
{
    FitAdult,
    FitYouth,
    FitChild
};

enum class LensCategory
{
    CategoryStandard,
    CategoryUVProtection,
    CategoryPolarized,
    CategoryPhotochromic
};

enum class AbsorbLevel
{
    AbsorbLow,
    AbsorbMedium,
    AbsorbHigh
};

enum class TowelDimension
{
    DimSmall,
    DimMedium,
    DimLarge,
    DimXLarge
};

enum class SwimStyle
{
    StyleBriefs,
    StyleTrunks,
    StyleJammers,
    StyleOnePiece,
    StyleBikini
};

class ValueConverter
{
public:
    static std::string convert(ProductMaterial mat);
    static std::string convert(ProductSize sz);
    static std::string convert(BallCategory ball);
    static std::string convert(GripType grip);
    static std::string convert(ItemColor col);
    static std::string convert(ResistanceLevel res);
    static std::string convert(StretchLevel str);
    static std::string convert(LensShade lens);
    static std::string convert(GoggleFit gog);
    static std::string convert(LensCategory lcat);
    static std::string convert(SwimStyle swim);
    static std::string convert(TowelDimension tow);
    static std::string convert(AbsorbLevel abs);
};

#endif
