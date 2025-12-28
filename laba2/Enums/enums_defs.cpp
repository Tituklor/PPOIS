#include "Enums_defs.h"
#include <string>

std::string ValueConverter::convert(ProductMaterial mat)
{
    switch (mat) {
        case ProductMaterial::RubberMaterial: return "rubber";
        case ProductMaterial::EVAMaterial: return "eva";
        case ProductMaterial::PlasticMaterial: return "plastic";
        case ProductMaterial::PVCMaterial: return "pvc";
        case ProductMaterial::LeatherMaterial: return "leather";
        case ProductMaterial::CottonMaterial: return "cotton";
        case ProductMaterial::PolyesterMaterial: return "polyester";
        case ProductMaterial::SpandexMaterial: return "spandex";
        case ProductMaterial::MicrofiberMaterial: return "microfiber";
        case ProductMaterial::BambooMaterial: return "bamboo";
        case ProductMaterial::SteelMaterial: return "steel";
        case ProductMaterial::WoodMaterial: return "wood";
        case ProductMaterial::TextileMaterial: return "textile";
        case ProductMaterial::FoamMaterial: return "foam";
        case ProductMaterial::MeshMaterial: return "mesh";
        case ProductMaterial::SyntheticMaterial: return "syntetic";
        case ProductMaterial::NylonMaterial: return "nylon";
        case ProductMaterial::SiliconeMaterial: return "silicone";
        case ProductMaterial::LatexMaterial: return "latex";
        case ProductMaterial::LycraMaterial: return "lycra";
        default: return "unknown";
    }
}

std::string ValueConverter::convert(ProductSize sz)
{
    switch (sz) {
        case ProductSize::SizeXS: return "XS";
        case ProductSize::SizeS: return "S";
        case ProductSize::SizeM: return "M";
        case ProductSize::SizeL: return "L";
        case ProductSize::SizeXL: return "XL";
        case ProductSize::SizeXXL: return "XXL";
        case ProductSize::SizeEU38: return "38";
        case ProductSize::SizeEU39: return "39";
        case ProductSize::SizeEU40: return "40";
        case ProductSize::SizeEU41: return "41";
        case ProductSize::SizeEU42: return "42";
        case ProductSize::SizeUniversal: return "universal";
        case ProductSize::SizeLarge: return "large";
        case ProductSize::SizeChild: return "child";
        default: return "unknown";
    }
}

std::string ValueConverter::convert(BallCategory ball)
{
    switch (ball) {
        case BallCategory::CategoryFitball: return "fitball";
        case BallCategory::CategoryMedball: return "medball";
        case BallCategory::CategoryPilates: return "pilates";
        case BallCategory::CategoryYoga: return "yoga";
        case BallCategory::CategoryExercise: return "exercise";
        default: return "unknown";
    }
}

std::string ValueConverter::convert(GripType grip)
{
    switch (grip) {
        case GripType::GripFoam: return "foam";
        case GripType::GripPlastic: return "plastic";
        case GripType::GripWood: return "wood";
        case GripType::GripRubber: return "rubber";
        default: return "unknown";
    }
}

std::string ValueConverter::convert(ItemColor col)
{
    switch (col) {
        case ItemColor::ColorBlack: return "black";
        case ItemColor::ColorWhite: return "white";
        case ItemColor::ColorRed: return "red";
        case ItemColor::ColorBlue: return "blue";
        case ItemColor::ColorGreen: return "green";
        case ItemColor::ColorNeonGreen: return "neon green";
        case ItemColor::ColorGray: return "gray";
        case ItemColor::ColorPink: return "pink";
        default: return "unknown";
    }
}

std::string ValueConverter::convert(ResistanceLevel res)
{
    switch (res) {
        case ResistanceLevel::LevelHigh: return "high";
        case ResistanceLevel::LevelMedium: return "medium";
        case ResistanceLevel::LevelLow: return "low";
        default: return "unknown";
    }
}

std::string ValueConverter::convert(StretchLevel str)
{
    switch (str) {
        case StretchLevel::StretchHigh: return "high";
        case StretchLevel::StretchMedium: return "medium";
        case StretchLevel::StretchLow: return "low";
        default: return "unknown";
    }
}

std::string ValueConverter::convert(LensShade lens)
{
    switch (lens) {
        case LensShade::ShadeClear: return "clear";
        case LensShade::ShadeBlue: return "blue";
        case LensShade::ShadeMirrored: return "mirrored";
        case LensShade::ShadeSmoke: return "smoke";
        case LensShade::ShadeYellow: return "yellow";
        case LensShade::ShadePink: return "pink";
        case LensShade::ShadeClubBranded: return "club";
        default: return "unknown";
    }
}

std::string ValueConverter::convert(GoggleFit gog)
{
    switch (gog) {
        case GoggleFit::FitAdult: return "adult";
        case GoggleFit::FitYouth: return "youth";
        case GoggleFit::FitChild: return "child";
        default: return "unknown";
    }
}

std::string ValueConverter::convert(LensCategory lcat)
{
    switch (lcat) {
        case LensCategory::CategoryStandard: return "standard";
        case LensCategory::CategoryUVProtection: return "uv protection";
        case LensCategory::CategoryPolarized: return "polarized";
        case LensCategory::CategoryPhotochromic: return "photochromic";
        default: return "unknown";
    }
}

std::string ValueConverter::convert(SwimStyle swim)
{
    switch (swim) {
        case SwimStyle::StyleBriefs: return "briefs";
        case SwimStyle::StyleTrunks: return "trunks";
        case SwimStyle::StyleJammers: return "jammers";
        case SwimStyle::StyleOnePiece: return "one piece";
        case SwimStyle::StyleBikini: return "bikini";
        default: return "unknown";
    }
}

std::string ValueConverter::convert(TowelDimension tow)
{
    switch (tow) {
        case TowelDimension::DimSmall: return "small";
        case TowelDimension::DimMedium: return "medium";
        case TowelDimension::DimLarge: return "large";
        case TowelDimension::DimXLarge: return "xlarge";
        default: return "unknown";
    }
}

std::string ValueConverter::convert(AbsorbLevel abs)
{
    switch (abs) {
        case AbsorbLevel::AbsorbLow: return "low";
        case AbsorbLevel::AbsorbMedium: return "medium";
        case AbsorbLevel::AbsorbHigh: return "high";
        default: return "unknown";
    }
}
