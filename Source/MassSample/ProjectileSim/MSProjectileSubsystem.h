﻿#pragma once
#include <ThirdParty/Vulkan/Include/vulkan/vulkan_core.h>

#include "CoreMinimal.h"
#include "MassEntitySubsystem.h"
#include "MassRepresentationProcessor.h"
#include "MSNiagaraActor.h"
#include "EntitySystem/MovieSceneEntityIDs.h"

#include "Field/FieldSystemNodes.h"
#include "MSProjectileSubsystem.generated.h"




UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Mass Sample Projectiles"))
class UMassProjectileSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	/**Default niagara bullet manager */
	UPROPERTY(config, EditAnywhere, Category = "Niagara")
	TSubclassOf<class UNiagaraSystem> DefaultNiagaraBulletManager;
	
};




//TODO: Might get around using this to store niagara fragments in the future
//It's still useful to serve as a place anything can get projectile info though...
UCLASS()
class UMSProjectileSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
protected:
	
	UMassEntitySubsystem* MassSubsystem;
	

	
	FMassArchetypeHandle BulletArchetype;


	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	
public:
	FSharedStruct GetOrCreateSharedNiagaraFragmentForSystemType(UNiagaraSystem* NiagaraSystem);

	
	/*This map lets us key based of of the hash of the NiagaraSystem pointer in new projectiles to see if they have an
	  existing manager actor*/
	TMap<uint32,AMSNiagaraActor*> PreexistingSharedNiagaraActors;

	//UFUNCTION(BlueprintCallable)
	//int32 SpawnProjectileEntity(FTransform Position, FVector Velocity, bool bRicochet);
	
};
