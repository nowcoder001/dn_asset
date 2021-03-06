﻿
using UnityEngine;

public interface IXPlayerAction
{

    // Use this for initialization
    void CameraWallEnter(AnimationCurve curve, Vector3 intersection, Vector3 cornerdir, float sector, float inDegree, float outDegree, bool positive);
    void CameraWallExit(float angle);

    void CameraWallVertical(float angle);

    void SetExternalString(string exString, bool bOnce);
    void TransferToSceneLocation(Vector3 pos, Vector3 forward);
    void TransferToNewScene(uint sceneID);
    void PlayCutScene(string cutscene);
    void GotoBattle();

    void GotoTerritoryBattle(int index);

    void GotoNest();
    void GotoFishing(int seatIndex, bool bFishing);

    bool IsValid { get; }

    Vector3 PlayerPosition(bool notplayertrigger);
    Vector3 PlayerLastPosition(bool notplayertrigger);

    void RefreshPosition();
}


