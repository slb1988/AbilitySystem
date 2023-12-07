// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AttributeSetBase.generated.h"

struct FGameplayEffectModCallbackData;
/**
 * 
 */
UCLASS()
class ABILITYSYSTEM_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAttributeSetBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AttributeSetBase")
	FGameplayAttributeData Health;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
