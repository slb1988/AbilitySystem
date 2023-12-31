// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "CharacterBase.generated.h"

class UAttributeSetBase;

UCLASS()
class ABILITYSYSTEM_API ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	UFUNCTION()
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="CharacterBase")
	UAbilitySystemComponent* AbilitySystemComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="CharacterBase")
	UAttributeSetBase* AttributeSetBaseComp;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable, Category="CharacterBase")
	void AquireAbility(TSubclassOf<UGameplayAbility> AbilityToAquire);

	UFUNCTION()
	void OnHealthChanged(float Health, float MaxHealth);
	UFUNCTION()
	void OnManaChanged(float Mana, float MaxMana);
	UFUNCTION()
	void OnStrengthChanged(float Strength, float MaxStrength);

	UFUNCTION(BlueprintImplementableEvent, Category="CharacterBase", meta=(AdvancedDisplay="OnHealthChanged"))
	void BP_OnHealthChanged(float Health, float MaxHealth);
	
	UFUNCTION(BlueprintImplementableEvent, Category="CharacterBase", meta=(AdvancedDisplay="OnManaChanged"))
	void BP_OnManaChanged(float Mana, float MaxMana);

	UFUNCTION(BlueprintImplementableEvent, Category="CharacterBase", meta=(AdvancedDisplay="OnStrengthChanged"))
	void BP_OnStrengthChanged(float Strength, float MaxStrength);
	
	UFUNCTION(BlueprintImplementableEvent, Category="CharacterBase", meta=(AdvancedDisplay="Die"))
	void BP_Die();
	
	UFUNCTION(BlueprintCallable, Category="CharacterBase")
	bool IsOtherHostile(ACharacterBase* Other);

	uint8 GetTeamID() const;
private:
	bool bIsDie;
	uint8 TeamID;
	void AutoDeterminTeamIDbyControllerType();

	void Dead();
};
