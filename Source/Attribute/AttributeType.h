#pragma once

#include "CoreMinimal.h"
#include "AttributeType.generated.h"

/** Attribute category type used to organise attributes */
UENUM(BlueprintType)
enum class EAttributeType : uint8
{
    None            UMETA(DisplayName = "None"),
    Vital           UMETA(DisplayName = "Vital"),
    Combat          UMETA(DisplayName = "Combat"),
    Elemental       UMETA(DisplayName = "Elemental"),
    Utility         UMETA(DisplayName = "Utility"),
    Weapon          UMETA(DisplayName = "Weapon"),
    Resistance      UMETA(DisplayName = "Resistance")
};

/** Vital stats for survival and energy */
UENUM(BlueprintType)
enum class EVitalAttribute : uint8
{
    Health          UMETA(DisplayName = "Health"),
    MaxHealth       UMETA(DisplayName = "Max Health"),
    Stamina         UMETA(DisplayName = "Stamina"),
    MaxStamina      UMETA(DisplayName = "Max Stamina"),
    Mana            UMETA(DisplayName = "Mana"),
    MaxMana         UMETA(DisplayName = "Max Mana"),
    Shield          UMETA(DisplayName = "Shield"),
    MaxShield       UMETA(DisplayName = "Max Shield"),
    Hunger          UMETA(DisplayName = "Hunger"),
    Thirst          UMETA(DisplayName = "Thirst")
};

/** Attributes related to offence and defence */
UENUM(BlueprintType)
enum class ECombatAttribute : uint8
{
    AttackPower     UMETA(DisplayName = "Attack Power"),
    DefensePower    UMETA(DisplayName = "Defense Power"),
    Accuracy        UMETA(DisplayName = "Accuracy"),
    Evasion         UMETA(DisplayName = "Evasion"),
    CriticalChance  UMETA(DisplayName = "Critical Chance"),
    CriticalDamage  UMETA(DisplayName = "Critical Damage"),
    ArmorPenetration UMETA(DisplayName = "Armor Penetration"),
    BlockChance     UMETA(DisplayName = "Block Chance")
};

/** Elemental-based damage and mitigation */
UENUM(BlueprintType)
enum class EElementalAttribute : uint8
{
    FireDamage      UMETA(DisplayName = "Fire Damage"),
    IceDamage       UMETA(DisplayName = "Ice Damage"),
    ElectricDamage  UMETA(DisplayName = "Electric Damage"),
    PoisonDamage    UMETA(DisplayName = "Poison Damage"),
    FireResist      UMETA(DisplayName = "Fire Resist"),
    IceResist       UMETA(DisplayName = "Ice Resist"),
    ElectricResist  UMETA(DisplayName = "Electric Resist"),
    PoisonResist    UMETA(DisplayName = "Poison Resist")
};

/** Utility stats used for general gameplay support */
UENUM(BlueprintType)
enum class EUtilityAttribute : uint8
{
    MovementSpeed       UMETA(DisplayName = "Movement Speed"),
    JumpHeight          UMETA(DisplayName = "Jump Height"),
    CooldownReduction   UMETA(DisplayName = "Cooldown Reduction"),
    Luck                UMETA(DisplayName = "Luck"),
    XPBoost             UMETA(DisplayName = "XP Boost"),
    GoldFind            UMETA(DisplayName = "Gold Find"),
    ItemDropRate        UMETA(DisplayName = "Item Drop Rate"),
    Stealth             UMETA(DisplayName = "Stealth")
};

/** Weapon-specific damage modifiers */
UENUM(BlueprintType)
enum class EWeaponAttribute : uint8
{
    MeleeDamage     UMETA(DisplayName = "Melee Damage"),
    RangedDamage    UMETA(DisplayName = "Ranged Damage"),
    MagicDamage     UMETA(DisplayName = "Magic Damage"),
    ReloadSpeed     UMETA(DisplayName = "Reload Speed"),
    FireRate        UMETA(DisplayName = "Fire Rate"),
    AmmoCapacity    UMETA(DisplayName = "Ammo Capacity")
};

/** Resistances vs specific effects */
UENUM(BlueprintType)
enum class EResistanceAttribute : uint8
{
    BleedResistance     UMETA(DisplayName = "Bleed Resistance"),
    BurnResistance      UMETA(DisplayName = "Burn Resistance"),
    FreezeResistance    UMETA(DisplayName = "Freeze Resistance"),
    ShockResistance     UMETA(DisplayName = "Shock Resistance"),
    KnockbackResistance UMETA(DisplayName = "Knockback Resistance"),
    FearResistance      UMETA(DisplayName = "Fear Resistance")
};

/** Attribute value with base and modified runtime data */
USTRUCT(BlueprintType)
struct FAttributeData
{
    GENERATED_BODY()

    FAttributeData()
        : BaseValue(0.f), CurrentValue(0.f), MinValue(0.f), MaxValue(100.f)
    {}

    /** Original value without modifiers */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
    float BaseValue;

    /** Runtime value after modifiers */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
    float CurrentValue;

    /** Minimum allowed value */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
    float MinValue;

    /** Maximum allowed value */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
    float MaxValue;
};
