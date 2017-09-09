﻿using System;
using UnityEngine;

[Serializable]
public class XEditorData
{
    //for serialized
    [SerializeField]
    public bool XResult_foldout;
    [SerializeField]
    public bool XHit_foldout;
    [SerializeField]
    public bool XJA_foldout;
    [SerializeField]
    public bool XMob_foldout;
    [SerializeField]
    public bool XFx_foldout;
    [SerializeField]
    public bool XWarning_foldout;
    [SerializeField]
    public bool XHitDummy_foldout;


    [SerializeField]
    public bool XAutoSelected;
    [SerializeField]
    public bool XFrameByFrame;
    [SerializeField]
    public bool XAutoJA = false;

    public void ToggleFold<T>(bool b) where T : XBaseData
    {
        Type t = typeof(T);

        if (t == typeof(XResultData)) XResult_foldout = b;
        else if (t == typeof(XJAData)) XJA_foldout = b;
        else if (t == typeof(XHitData)) XHit_foldout = b;
        else if (t == typeof(XFxData)) XFx_foldout = b;
        else if (t == typeof(XWarningData)) XWarning_foldout = b;
        else if (t == typeof(XMobUnitData)) XMob_foldout = b;
    }
}

public class XHitConfLibrary
{
   
    public static float Hit_PresentStraight;
    public static float Hit_HardStraight;
    public static float Hit_Offset;
    public static float Hit_Height;

    static string GetValue(string key)
    {
        string ret = "";
        //uint k = XCommon.singleton.XHash(key);
        //if (_table.Table.TryGetValue(k, out ret))
        //{
        //    return ret;
        //}

        return ret;
    }
    static XHitConfLibrary()
    {
        //XTableReader.ReadFile(@"Table/GlobalConfig", _table);

        //Hit_PresentStraight = XParse.Parse(GetValue("PresentStraight"));
        //Hit_HardStraight = XParse.Parse(GetValue("HardStraight"));
        //Hit_Offset = XParse.Parse(GetValue("Offset"));
        //Hit_Height = XParse.Parse(GetValue("Height"));
    }
}