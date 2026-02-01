class Kimi_HMD_Modes_Pilot
{
    topLeft="HUD_top_left";
    topRight="HUD_top_right";
    bottomLeft="HUD_bottom_left";
    borderLeft=0;
    borderRight=0;
    borderTop=0;
    borderBottom=0;
    color[]={0.212,0.76899999,0.204,0.2};
    enableParallax=0;
    helmetMountedDisplay=1;
    helmetPosition[]={-0.039999999,0.039999999,0.1};
    helmetRight[]={0.079999998,0,0};
    helmetDown[]={0,-0.079999998,0};
    class Bones
    {
        class PlaneOrientation
        {
            type="fixed";
            pos[]={0.5,0.5};
        };
        class Limit0109
        {
            type="limit";
            limits[]={0.1,0.1,0.89999998,0.89999998};
        };
        class ForwardVec
        {
            type="vector";
            source="forward";
            pos0[]={0,0};
            pos10[]={0.21600001,0.21600001};
        };
        class ForwardVec_Center
        {
            type="vector";
            source="forward";
            pos0[]={0.5,0.5};
            pos10[]=
            {
                "0.500 + 0.2165",
                "0.500 + 0.2165"
            };
        };
        class ForwardVecPNVS
        {
            type="vector";
            source="forward";
            pos0[]={0,0};
            pos10[]={-0.055,-0.055};
        };
        class VspeedBone
        {
            type="linear";
            source="vspeed";
            sourceScale=1.9685;
            min=-20;
            max=20;
            minPos[]={0.93000001,0.2};
            maxPos[]={0.93000001,0.80000001};
        };
        class RadarAltitudeBone
        {
            type="linear";
            source="altitudeAGL";
            sourceOffset=-6;
            sourceScale=3.2808399;
            min=0;
            max=200;
            minPos[]={0.96499997,0.2};
            maxPos[]={0.96499997,0.80000001};
        };
        class WYPT_Tape_Bone
        {
            type="vector";
            source="wppoint";
            pos0[]={0.5,0.12800001};
            pos10[]=
            {
                "0.500 + 0.037",
                0.12800001
            };
        };
        class Tape_Limit
        {
            type="limit";
            limits[]={0.2,0,0.80000001,1};
        };
        class Turret_Tape_Bone
        {
            type="vector";
            source="Turret";
            pos0[]={0.5,0.12800001};
            pos10[]=
            {
                "0.500 + 0.037",
                0.12800001
            };
            projection=1;
        };
        class GunnerAim
        {
            type="vector";
            source="turret";
            pos0[]={0,-2};
            pos10[]={0.0071700001,-0.0099999998};
            projection=0;
        };
        class Gunner_HAD_Limit
        {
            type="limit";
            limits[]={0.40000001,0.86000001,0.60000002,0.94};
        };
        class Slip_Ball_X
        {
            type="vector";
            source="velocity";
            pos0[]={0.5,0.84299999};
            pos10[]={0.51499999,0.84299999};
        };
        class GforceX_Slip
        {
            type="linear";
            source="gmeterX";
            sourceScale=1;
            max=0.15000001;
            min=-0.15000001;
            minPos[]=
            {
                "0.5+0.1",
                "0.9-0.04-0.02"
            };
            maxPos[]=
            {
                "0.5-0.1",
                "0.9-0.04-0.02"
            };
        };
        class WeaponAim: ForwardVec_Center
        {
            source="weapon";
        };
        class TurretAimToView
        {
            type="vector";
            source="weapontoview";
            pos0[]={0.5,0.5};
            pos10[]=
            {
                "0.500 + 0.2165",
                "0.500 + 0.2165"
            };
        };
        class CCIP: ForwardVec_Center
        {
            source="impactpoint";
        };
        class CCIP_2_VIEW: CCIP
        {
            source="impactpointtoview";
        };
        class RocketAim: ForwardVec_Center
        {
            source="weapon";
        };
        class Target: ForwardVec_Center
        {
            source="target";
        };
        class Target2View: Target
        {
            source="targetToView";
        };
        class WYPT_2_VIEW: ForwardVec_Center
        {
            source="wppointtoview";
        };
        class Velocity: ForwardVec_Center
        {
            source="velocityToView";
        };
        class HorizonBankRot
        {
            type="rotational";
            source="horizonBank";
            center[]={0.5,0.5};
            min=-3.1415999;
            max=3.1415999;
            minAngle=-180;
            maxAngle=180;
            aspectRatio=1;
        };
        class Speed_X_Hover_P
        {
            type="vector";
            source="velocity";
            pos0[]={0,0};
            pos10[]={0.02,0};
        };
        class Speed_X_Hover_N
        {
            type="vector";
            source="velocityToView";
            sourcescale="1";
            pos0[]={0,0};
            pos10[]={0.02,0.02};
        };
        class Speed_Z_Hover
        {
            type="linear";
            source="speed";
            sourcescale="1.94384";
            max=20;
            min=-20;
            minPos[]={0.5,0.25};
            maxPos[]={0.5,0.75};
        };
        class Speed_X_Transition
        {
            type="vector";
            source="velocity";
            pos0[]={0,0};
            pos10[]={0.02,0};
        };
        class Speed_Z_Transition
        {
            type="linear";
            source="speed";
            sourcescale="1.94384";
            max=60;
            min=-60;
            minPos[]={0.5,0.25};
            maxPos[]={0.5,0.75};
        };
        class GforceX_Hover
        {
            type="linear";
            source="gmeterX";
            Sourcescale=1;
            max=7;
            min=-7;
            minPos[]={0.25,0};
            maxPos[]={-0.25,0};
        };
        class GforceZ_Hover
        {
            type="linear";
            source="gmeterZ";
            Sourcescale=1;
            max=7;
            min=-7;
            minPos[]={0,-0.25};
            maxPos[]={0,0.25};
        };
        class GforceX_Transition
        {
            type="linear";
            source="gmeterX";
            Sourcescale=1;
            max=7;
            min=-7;
            minPos[]={0.1,0};
            maxPos[]={-0.1,0};
        };
        class GforceZ_Transition
        {
            type="linear";
            source="gmeterZ";
            Sourcescale=1;
            max=7;
            min=-7;
            minPos[]={0,-0.1};
            maxPos[]={0,0.1};
        };
        class Level0_Transition
        {
            type="horizon";
            pos0[]={0.5,0.5};
            pos10[]={0.64999998,0.64999998};
            angle=0;
        };
        class Level0
        {
            type="horizon";
            pos0[]={0.5,0.5};
            pos10[]={0.77999997,0.77999997};
            angle=0;
        };
        class LevelP5: Level0
        {
            angle=5;
        };
        class LevelM5: Level0
        {
            angle=-5;
        };
        class LevelP10: Level0
        {
            angle=10;
        };
        class LevelM10: Level0
        {
            angle=-10;
        };
        class LevelP15: Level0
        {
            angle=15;
        };
        class LevelM15: Level0
        {
            angle=-15;
        };
        class LevelP20: Level0
        {
            angle=20;
        };
        class LevelM20: Level0
        {
            angle=-20;
        };
        class LevelP25: Level0
        {
            angle=25;
        };
        class LevelM25: Level0
        {
            angle=-25;
        };
        class LevelP30: Level0
        {
            angle=30;
        };
        class LevelM30: Level0
        {
            angle=-30;
        };
        class LevelP35: Level0
        {
            angle=35;
        };
        class LevelM35: Level0
        {
            angle=-35;
        };
        class LevelP40: Level0
        {
            angle=40;
        };
        class LevelM40: Level0
        {
            angle=-40;
        };
        class LevelP45: Level0
        {
            angle=45;
        };
        class LevelM45: Level0
        {
            angle=-45;
        };
        class LevelP50: Level0
        {
            angle=50;
        };
        class LevelM50: Level0
        {
            angle=-50;
        };
    };
    class Draw
    {
        color[]=
        {
            "user3",
            "user4",
            "user5"
        };
        alpha="user6";
        condition="on*user0-user2";
        class WYPT_Group
        {
            type="group";
            condition="WPvalid";
            class WYPT_Block
            {
                type="group";
                condition="speed - (6*1.852/3.6)+1.94384";
                class WYPT_Text
                {
                    type="text";
                    source="static";
                    text="W";
                    align="left";
                    scale=1;
                    pos[]=
                    {
                        {0.029999999,0.75},
                        1
                    };
                    right[]=
                    {
                        {0.07,0.75},
                        1
                    };
                    down[]=
                    {
                        {0.029999999,0.79000002},
                        1
                    };
                };
                class WYPT_Index
                {
                    type="text";
                    source="WPIndex";
                    sourceScale=1;
                    align="right";
                    scale=1;
                    pos[]=
                    {
                        {0.039999999,0.75},
                        1
                    };
                    right[]=
                    {
                        {0.079999998,0.75},
                        1
                    };
                    down[]=
                    {
                        {0.039999999,0.79000002},
                        1
                    };
                };
                class WYPT_Distance
                {
                    type="text";
                    source="WPDist";
                    sourceScale=0.001;
                    sourceprecision=2;
                    align="right";
                    scale=1;
                    pos[]=
                    {
                        {0.12,0.75},
                        1
                    };
                    right[]=
                    {
                        {0.16,0.75},
                        1
                    };
                    down[]=
                    {
                        {0.12,0.79000002},
                        1
                    };
                };
                class WYPT_KM
                {
                    type="text";
                    source="static";
                    text="KM";
                    align="left";
                    scale=1;
                    pos[]=
                    {
                        {0.22,0.75},
                        1
                    };
                    right[]=
                    {
                        {0.25999999,0.75},
                        1
                    };
                    down[]=
                    {
                        {0.22,0.79000002},
                        1
                    };
                };
                class Ground_Speed_M
                {
                    type="group";
                    condition="1-user1";
                    class GS_M
                    {
                        type="text";
                        source="Speed";
                        sourceScale=3.5999999;
                        align="center";
                        scale=1;
                        pos[]=
                        {
                            {0.029999999,0.79000002},
                            1
                        };
                        right[]=
                        {
                            {0.07,0.79000002},
                            1
                        };
                        down[]=
                        {
                            {0.029999999,0.82999998},
                            1
                        };
                    };
                };
                class Ground_Speed_I
                {
                    type="group";
                    condition="user1";
                    class GS_I
                    {
                        type="text";
                        source="Speed";
                        sourceScale=1.94384;
                        align="center";
                        scale=1;
                        pos[]=
                        {
                            {0.029999999,0.79000002},
                            1
                        };
                        right[]=
                        {
                            {0.07,0.79000002},
                            1
                        };
                        down[]=
                        {
                            {0.029999999,0.82999998},
                            1
                        };
                    };
                };
                class WYPT_TTG_6
                {
                    type="group";
                    condition="(6*1.852/3.6) - speed";
                    class TTG_6
                    {
                        type="text";
                        source="WPDist";
                        sourceScale="1/(6*1.852/3.6)";
                        align="right";
                        scale=1;
                        pos[]=
                        {
                            {0.13,0.79000002},
                            1
                        };
                        right[]=
                        {
                            {0.17,0.79000002},
                            1
                        };
                        down[]=
                        {
                            {0.13,0.82999998},
                            1
                        };
                    };
                };
                class WYPT_TTG_10
                {
                    type="group";
                    condition="speed- ((10-6)*1.852/3.6)+1";
                    class TTG_10
                    {
                        type="group";
                        condition="(10*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(10*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_20
                {
                    type="group";
                    condition="speed- ((20-10)*1.852/3.6)+1";
                    class TTG_20
                    {
                        type="group";
                        condition="(20*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(20*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_30
                {
                    type="group";
                    condition="speed- ((30-10)*1.852/3.6)+1";
                    class TTG_30
                    {
                        type="group";
                        condition="(30*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(30*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_40
                {
                    type="group";
                    condition="speed- ((40-10)*1.852/3.6)+1";
                    class TTG_40
                    {
                        type="group";
                        condition="(40*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(40*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_50
                {
                    type="group";
                    condition="speed- ((50-10)*1.852/3.6)+1";
                    class TTG_50
                    {
                        type="group";
                        condition="(50*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(50*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_60
                {
                    type="group";
                    condition="speed- ((60-10)*1.852/3.6)+1";
                    class TTG_60
                    {
                        type="group";
                        condition="(60*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(60*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_70
                {
                    type="group";
                    condition="speed- ((70-10)*1.852/3.6)+1";
                    class TTG_70
                    {
                        type="group";
                        condition="(70*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(70*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_80
                {
                    type="group";
                    condition="speed- ((80-10)*1.852/3.6)+1";
                    class TTG_80
                    {
                        type="group";
                        condition="(80*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(80*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_90
                {
                    type="group";
                    condition="speed- ((90-10)*1.852/3.6)+1";
                    class TTG_90
                    {
                        type="group";
                        condition="(90*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(90*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_100
                {
                    type="group";
                    condition="speed- ((100-10)*1.852/3.6)+1";
                    class TTG_100
                    {
                        type="group";
                        condition="(100*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(100*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_110
                {
                    type="group";
                    condition="speed- ((110-10)*1.852/3.6)+1";
                    class TTG_110
                    {
                        type="group";
                        condition="(110*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(110*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_120
                {
                    type="group";
                    condition="speed- ((120-10)*1.852/3.6)+1";
                    class TTG_120
                    {
                        type="group";
                        condition="(120*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(120*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_130
                {
                    type="group";
                    condition="speed- ((130-10)*1.852/3.6)+1";
                    class TTG_130
                    {
                        type="group";
                        condition="(130*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(130*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_140
                {
                    type="group";
                    condition="speed- ((140-10)*1.852/3.6)+1";
                    class TTG_140
                    {
                        type="group";
                        condition="(140*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(140*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_150
                {
                    type="group";
                    condition="speed- ((150-10)*1.852/3.6)+1";
                    class TTG_150
                    {
                        type="group";
                        condition="(150*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(150*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_160
                {
                    type="group";
                    condition="speed- ((160-10)*1.852/3.6)+1";
                    class TTG_160
                    {
                        type="group";
                        condition="(160*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(160*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_170
                {
                    type="group";
                    condition="speed- ((170-10)*1.852/3.6)+1";
                    class TTG_170
                    {
                        type="group";
                        condition="(170*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(170*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_180
                {
                    type="group";
                    condition="speed- ((180-10)*1.852/3.6)+1";
                    class TTG_180
                    {
                        type="group";
                        condition="(180*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(180*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_190
                {
                    type="group";
                    condition="speed- ((190-10)*1.852/3.6)+1";
                    class TTG_190
                    {
                        type="group";
                        condition="(190*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(190*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_200
                {
                    type="group";
                    condition="speed- ((200-10)*1.852/3.6)+1";
                    class TTG_200
                    {
                        type="group";
                        condition="(200*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(200*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_210
                {
                    type="group";
                    condition="speed- ((210-10)*1.852/3.6)+1";
                    class TTG_210
                    {
                        type="group";
                        condition="(210*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(210*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_220
                {
                    type="group";
                    condition="speed- ((220-10)*1.852/3.6)+1";
                    class TTG_220
                    {
                        type="group";
                        condition="(220*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(220*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_230
                {
                    type="group";
                    condition="speed- ((230-10)*1.852/3.6)+1";
                    class TTG_230
                    {
                        type="group";
                        condition="(230*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(230*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_240
                {
                    type="group";
                    condition="speed- ((240-10)*1.852/3.6)+1";
                    class TTG_240
                    {
                        type="group";
                        condition="(240*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(240*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_250
                {
                    type="group";
                    condition="speed- ((250-10)*1.852/3.6)+1";
                    class TTG_250
                    {
                        type="group";
                        condition="(250*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(250*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_260
                {
                    type="group";
                    condition="speed- ((260-10)*1.852/3.6)+1";
                    class TTG_260
                    {
                        type="group";
                        condition="(260*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(260*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_270
                {
                    type="group";
                    condition="speed- ((270-10)*1.852/3.6)+1";
                    class TTG_270
                    {
                        type="group";
                        condition="(270*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(270*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_280
                {
                    type="group";
                    condition="speed- ((280-10)*1.852/3.6)+1";
                    class TTG_280
                    {
                        type="group";
                        condition="(280*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(280*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_290
                {
                    type="group";
                    condition="speed- ((290-10)*1.852/3.6)+1";
                    class TTG_290
                    {
                        type="group";
                        condition="(290*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(290*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
                class WYPT_TTG_300
                {
                    type="group";
                    condition="speed- ((300-10)*1.852/3.6)+1";
                    class TTG_300
                    {
                        type="group";
                        condition="(300*1.852/3.6) - speed";
                        class TTG
                        {
                            type="text";
                            source="WPDist";
                            sourceScale="1/(300*1.852/3.6)";
                            align="right";
                            scale=1;
                            pos[]=
                            {
                                {0.13,0.79000002},
                                1
                            };
                            right[]=
                            {
                                {0.17,0.79000002},
                                1
                            };
                            down[]=
                            {
                                {0.13,0.82999998},
                                1
                            };
                        };
                    };
                };
            };
        };
        class Hover_Box
        {
            type="group";
            condition="autohover";
            class Hover_box_box
            {
                type="line";
                width=3;
                points[]=
                {
                    
                    {
                        
                        {
                            "0.02 + 0.00",
                            "0.50 - 0.015"
                        },
                        1
                    },
                    
                    {
                        
                        {
                            "0.02 + 0.010",
                            "0.50 - 0.025"
                        },
                        1
                    },
                    
                    {
                        
                        {
                            "0.02 + 0.065",
                            "0.50 - 0.025"
                        },
                        1
                    },
                    
                    {
                        
                        {
                            "0.02 + 0.075",
                            "0.50 - 0.015"
                        },
                        1
                    },
                    
                    {
                        
                        {
                            "0.02 + 0.075",
                            "0.50 + 0.015"
                        },
                        1
                    },
                    
                    {
                        
                        {
                            "0.02 + 0.065",
                            "0.50 + 0.025"
                        },
                        1
                    },
                    
                    {
                        
                        {
                            "0.02 + 0.010",
                            "0.50 + 0.025"
                        },
                        1
                    },
                    
                    {
                        
                        {
                            "0.02 + 0.00",
                            "0.50 + 0.015"
                        },
                        1
                    },
                    
                    {
                        
                        {
                            "0.02 + 0.00",
                            "0.50 - 0.015"
                        },
                        1
                    }
                };
            };
        };
        class Transition_Mode
        {
            type="group";
            condition="1-autohover";
            class Transition
            {
                type="group";
                condition="speed - (6*1.852/3.6)+1";
                class Transition_VV
                {
                    type="group";
                    condition="(60*1.852/3.6) - speed";
                    class Velocity_Vector
                    {
                        type="line";
                        width=2;
                        points[]=
                        {
                            
                            {
                                {0.5,0.5},
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                
                                {
                                    "0 * 0.075",
                                    "-0.02 * 0.075"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                
                                {
                                    "0.0099999998 * 0.075",
                                    "-0.01732 * 0.075"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                
                                {
                                    "0.01732 * 0.075",
                                    "-0.0099999998 * 0.075"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                
                                {
                                    "0.02 * 0.075",
                                    "0 * 0.075"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                
                                {
                                    "0.01732 * 0.075",
                                    "0.0099999998 * 0.075"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                
                                {
                                    "0.0099999998 * 0.075",
                                    "0.01732 * 0.075"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                
                                {
                                    "0 * 0.075",
                                    "0.02 * 0.075"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                
                                {
                                    "-0.0099999998 * 0.075",
                                    "0.01732 * 0.075"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                
                                {
                                    "-0.01732 * 0.075",
                                    "0.0099999998 * 0.075"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                
                                {
                                    "-0.02 * 0.075",
                                    "0 * 0.075"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                
                                {
                                    "-0.01732 * 0.075",
                                    "-0.0099999998 * 0.075"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                
                                {
                                    "-0.0099999998 * 0.075",
                                    "-0.01732 * 0.075"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                
                                {
                                    "0 * 0.075",
                                    "-0.02 * 0.075"
                                },
                                1
                            }
                        };
                    };
                };
                class Transition_Acceleration_ball
                {
                    type="group";
                    condition="(60*1.852/3.6) - speed";
                    class Acceleration_ball
                    {
                        type="line";
                        width=3;
                        points[]=
                        {
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                "GforceZ_Transition",
                                1,
                                "GforceX_Transition",
                                1,
                                
                                {
                                    "0 * 0.50",
                                    "-0.02 * 0.50"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                "GforceZ_Transition",
                                1,
                                "GforceX_Transition",
                                1,
                                
                                {
                                    "0.0099999998 * 0.50",
                                    "-0.01732 * 0.50"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                "GforceZ_Transition",
                                1,
                                "GforceX_Transition",
                                1,
                                
                                {
                                    "0.01732 * 0.50",
                                    "-0.0099999998 * 0.50"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                "GforceZ_Transition",
                                1,
                                "GforceX_Transition",
                                1,
                                
                                {
                                    "0.02 * 0.50",
                                    "0 * 0.50"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                "GforceZ_Transition",
                                1,
                                "GforceX_Transition",
                                1,
                                
                                {
                                    "0.01732 * 0.50",
                                    "0.0099999998 * 0.50"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                "GforceZ_Transition",
                                1,
                                "GforceX_Transition",
                                1,
                                
                                {
                                    "0.0099999998 * 0.50",
                                    "0.01732 * 0.50"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                "GforceZ_Transition",
                                1,
                                "GforceX_Transition",
                                1,
                                
                                {
                                    "0 * 0.50",
                                    "0.02 * 0.50"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                "GforceZ_Transition",
                                1,
                                "GforceX_Transition",
                                1,
                                
                                {
                                    "-0.0099999998 * 0.50",
                                    "0.01732 * 0.50"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                "GforceZ_Transition",
                                1,
                                "GforceX_Transition",
                                1,
                                
                                {
                                    "-0.01732 * 0.50",
                                    "0.0099999998 * 0.50"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                "GforceZ_Transition",
                                1,
                                "GforceX_Transition",
                                1,
                                
                                {
                                    "-0.02 * 0.50",
                                    "0 * 0.50"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                "GforceZ_Transition",
                                1,
                                "GforceX_Transition",
                                1,
                                
                                {
                                    "-0.01732 * 0.50",
                                    "-0.0099999998 * 0.50"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                "GforceZ_Transition",
                                1,
                                "GforceX_Transition",
                                1,
                                
                                {
                                    "-0.0099999998 * 0.50",
                                    "-0.01732 * 0.50"
                                },
                                1
                            },
                            
                            {
                                "Speed_Z_Transition",
                                1,
                                "Speed_X_Transition",
                                1,
                                "GforceZ_Transition",
                                1,
                                "GforceX_Transition",
                                1,
                                
                                {
                                    "0 * 0.50",
                                    "-0.02 * 0.50"
                                },
                                1
                            }
                        };
                    };
                };
                class Transition_Horizon
                {
                    clipTL[]={0.15000001,0.15000001};
                    clipBR[]={0.85000002,0.85000002};
                    type="group";
                    class Horizon
                    {
                        class Level0
                        {
                            type="line";
                            width=4;
                            points[]=
                            {
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "-0.05*9",
                                        0
                                    },
                                    1
                                },
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "-0.05*8",
                                        0
                                    },
                                    1
                                },
                                {},
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "-0.05*7",
                                        0
                                    },
                                    1
                                },
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "-0.05*6",
                                        0
                                    },
                                    1
                                },
                                {},
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "-0.05*5",
                                        0
                                    },
                                    1
                                },
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "-0.05*4",
                                        0
                                    },
                                    1
                                },
                                {},
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "-0.05*3",
                                        0
                                    },
                                    1
                                },
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "-0.05*2",
                                        0
                                    },
                                    1
                                },
                                {},
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "0.05*9",
                                        0
                                    },
                                    1
                                },
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "0.05*8",
                                        0
                                    },
                                    1
                                },
                                {},
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "0.05*7",
                                        0
                                    },
                                    1
                                },
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "0.05*6",
                                        0
                                    },
                                    1
                                },
                                {},
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "0.05*5",
                                        0
                                    },
                                    1
                                },
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "0.05*4",
                                        0
                                    },
                                    1
                                },
                                {},
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "0.05*3",
                                        0
                                    },
                                    1
                                },
                                
                                {
                                    "Level0_Transition",
                                    
                                    {
                                        "0.05*2",
                                        0
                                    },
                                    1
                                }
                            };
                        };
                    };
                };
                class Transition_Bank
                {
                    type="group";
                    class Transition_Bank_Cue
                    {
                        type="polygon";
                        points[]=
                        {
                            
                            {
                                
                                {
                                    "HorizonBankRot",
                                    {0,0.25},
                                    1
                                },
                                
                                {
                                    "HorizonBankRot",
                                    {-0.0099999998,0.23},
                                    1
                                },
                                
                                {
                                    "HorizonBankRot",
                                    {0.0099999998,0.23},
                                    1
                                }
                            }
                        };
                    };
                };
            };
        };
        class Cruise_Mode
        {
            type="group";
            condition="1-autohover";
            class Cruise
            {
                type="group";
                condition="speed - (60*1.852/3.6)+1";
            };
        };
    };
};