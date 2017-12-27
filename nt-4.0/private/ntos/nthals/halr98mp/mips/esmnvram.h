#ident	"@(#) NEC esmnvram.h 1.1 95/02/20 16:50:43"
/**************************************************************** 
 ******* 	Copyright (C) 1994 NEC Corporation  	  ******* 
 ****************************************************************/

/*******

    File Name:
	
	envram.h  

    Abstract:
 
   	This module contains the definitions for the extended NVRAM.
	
    Author:

	Takehiro Ueda (tueda@oa2.kb.nec.co.jp) 	12/22/1994
 
    Modification History:

    	- M000 12/22/94 -   
		created.
		
*******/



/*******************************************************************************
 ********     NVRAM��8K�Х��ȡˤ������ե����ޥåȤ�ʲ��˵��Ҥ��롣     ********
 *******************************************************************************
 *
 *   S001  11/22/94
 *	�쥳���ɤ�ͭ��/̵���ե饰��Check̤/�ѥե饰��ƥ쥳���ɤ���Ƭ�ˤ�����
 *      �ޤȤ�ƥ쥳���ɥ꡼��������Ƭ�ˤ������ǡ��쥳���ɤν�����ˡ���Ѥ�ä�
 *	���롣��Ԥϥ����ॢ�����������Ԥϥ������󥷥�륢�������ˤय��
 *	��������Ԥ���ѡ�
 * 	
 *	�Ԥ���Ƭ�ˤ�������ϳ�����Ƥ�Х��ȿ��򤢤�魯��
 *
 *	�ܻ��ͤˤ������äƹ�¤�Τ����ͽ�ꡣ
 *   
 *   S002  11/26/94
 *     	���ΰ��ECC��Ϣ���ѥ˥å������Ϣ������ƥ����륨�顼������Ϣ��etc.��
 *   	����Ƭ�Υإå���������NVRAM����Ƭ�˰ܤ���NVRAM����Ƭ�ˤ���إå����
 *	���ΰ�Υ쥳���ɤ�ľ�ܥ����������뤿��Υ��ե��åȤ��Ĥ褦�ˤ��롣
 * 
 *      NVRAM�Υ����������ˤ�256�Х���ñ�̤ǥХ��ڤ괹���������ʤ��뤿��
 *      �ƥǡ�����256�Х���Ĺ�ʲ��Τ�Ρˤ�256�Х��ȥХ�������ޤ�����ʤ��褦
 *      ����θ�����ΰ��ECC��Ϣ���ѥ˥å������Ϣ��etc.�ˤ���Ƭ��ɬ��256�Х���
 *      �Х�����꤫�鳫�Ϥ����褦�ˤ��롣
 *
 *	ECC���顼�������SIMM���경�����2�Х��Ȥ���1�Х��Ȥ��ѹ���
 *
 *  	�ɥ��ե��å� �ɤϤ��٤�NVRAM����Ƭ����Υ��ե��åȡ�
 *
 *   S003  12/13/94
 *	NW����������Ȥȥ��ꥨ�顼���ꥢ���̲����뤿����Ƭ512�Х��Ȥ�
 *	���ꥨ�顼���ꥢ�Ȥ����ե����ޥåȤ�NW����������Ȥ����줹�롣
 *
 *  	STEP1�Ǥϥ�������Ԥ�ʤ������ܥ��ꥢ�ϻ��Ѥ��ʤ���
 *	�ܥ��ꥨ�顼���ꥢ��NW����������ȤȤζ��̲��Τ���˿������ߤ���
 *	��ΤǤ��ꡢ���������ECC���顼�����ΰ�Ϥ��Τޤ޻Ĥ롣
 *
 *	512�Х��ȤΥ��ꥢ����Ƭ���ߤ��뤿�ᡢ��������Τ���¾���Ƥξ����ΰ��
 *	512�Х��ȥ��ե��åȤ��礭���ʤ뤳�Ȥˤʤ롣
 *
 *	�����ƥ���󥨥ꥢ�ؤΥ��ե��å�2�Х��Ȥ��ɲá�
 *
 *	���ե��åȤκƷ׻���
 *
 *   S004  12/14/94
 *	��¤�κ�����
 *
 *	�ǥѥ˥å� �Ǥ�ǥ��ȥåץ��顼 �Ǥ��ѹ���
 *
 *   S005  12/23/94
 *	4byte alignment�ˤ��ʤ��ƥѥǥ��󥰤�����ѹ���
 *
 *	���ȥåץ��顼�Υե饰��2�ӥåȤ˿���������ɲá�
 *
 *      �����ƥ���󥨥ꥢ��NVRAM�إå��ˤȤꤳ�ࡣ
 *	����ˤȤ�ʤ������ƥ���󥨥ꥢ�ؤΥ��ե��åȤ����פȤʤ뤿��
 *	2�Х���ʬ̤���ѤȤ��롣
 *
 *	�����ƥ���󥨥ꥢ�˥ޥ��å��ʥ�С����ɲá������ե����ޥåȤ�̵ͭ��
 *	�ޥ��å��ʥ�С��ȥե饰�ǥ����å�����褦�ˤ��롣�ޥ��å��ʥ�С���
 *      0xFF651026�Ȥ��롣
 *
 *	�ǥ��ȥåץ��顼 �Ǥ�ǥ����ƥ२�顼 �Ǥ��ѹ���
 *
 *   S006  12/27/94
 *	#pragma pack() ���ɲ�
 *
 *      char reserved[49] �� char reserved[49] �˽��������ѹ���harmless�Ǥ���
 *	�ȿ�����... (^_^;
 *	
 *	unsigned short offset_ecc2err �� offset_2biterr�˽��������ѹ���
 *	harmless�Ǥ���ȿ�����... (^_^;
 *
 ******************************************************************************


 ################### 
 #  NVRAM�إå���  #
 ###################

     ######################################################
     #  F/W�ѥ��꡼���顼���ꥢ (NW����������Ȥȶ���)  #
     ######################################################

	 512    ���ꥨ�顼����쥳����(2�Х���) �� 256

		 #################### 
  		 #  �쥳���ɤ�����  #
		 ####################  

	   	����1	���ơ����� 		0:����	1:�۾�(2bit���顼̵ͭ)
		    1   1bit���顼�������

���� ###################### 
     #  ���Τ˴ؤ�����  #
     ######################

	   1	NVRAM�ξ��֤򤢤�魯�ե饰

	         ##################
		 #  �ե饰������  #
		 ##################

		����0	NVRAM����ͭ��/̵��      0:̵��	1:ͭ��
		  ��1	�����ե����ޥåȤ�̵ͭ  0:̵ 	1:ͭ
		����2	READ-ONLY		0:NO 	1:YES
		����3	LOCK			0:NO 	1:YES
		����4	[reserved]
		����5       ������
		����6       ������
		����7       ������
	  14	NVRAM���ե����ޥåȤ��줿�����ॹ�����

	   3    [ reserved ]

���� ###############################
     #  ALIVE�����ΰ�˴ؤ�����  #
     ###############################

	   2    ALIVE�����ΰ�ؤΥ��ե��å�

���� #######################################
     #  ECC1bit���顼�����ΰ�˴ؤ�����  #
     #######################################

	   2    ECC 1bit���顼����������Ƭ�ؤΥ��ե��å�
	�� 2    ECC 1bit���顼����1�쥳���ɥ�����
           2    ECC 1bit���顼�����쥳���ɿ�
	   2    ECC 1bit���顼��������ֺǸ����Ͽ�����쥳���ɤؤΥ��ե��å�
	   4    ���ֺǸ��ECC1bit���顼���Υ꡼�ɥǡ���
	�� 8	ECC 1bit���顼������� 	�� ���ꥰ�롼�׿�8

���� #######################################
     #  ECC2bit���顼�����ΰ�˴ؤ�����  #
     #######################################

	   2    ECC 2bit���顼����������Ƭ�ؤΥ��ե��å�
	�� 2    ECC 2bit���顼����1�쥳���ɥ�����
           2    ECC 2bit���顼�����쥳���ɿ�
	   2    ECC 2bit���顼��������ֺǸ����Ͽ�����쥳���ɤؤΥ��ե��å�
           4	���ֺǸ��ECCʣ��bit���顼���Υ꡼�ɥǡ���
	   4    SIMM�򴹥ե饰		�� ���ꥰ�롼�׿�4

		 ##################
		 #  �ե饰������  #
		 ##################

		����0	���롼��N��SIMM #0 (N=1��4) 0:OK 1:NG(�׸�)
		����1	���롼��N��SIMM #1    	��
		����2	���롼��N��SIMM #2����	��
		����3	���롼��N��SIMM #3����	��
		����4	[reserved]
		����5	   ��
		����6	   ��
		����7��������
	   4    [reserved]

���� ########################################
 ����#  �����ƥ२�顼�����ΰ�˴ؤ�����  #
 ����########################################

	   2    �����ƥ२�顼����������Ƭ�ؤΥ��ե��å�
	�� 2    �����ƥ२�顼����1�쥳���ɥ�����
           2    �����ƥ२�顼����쥳���ɿ�
	   2    �����ƥ२�顼�������ֺǸ����Ͽ�����쥳���ɤؤΥ��ե��å�

���� ############################################
 ����#  ����ƥ����륨�顼�����ΰ�˴ؤ�����  #
     ############################################

	   2    ����ƥ����륨�顼����������Ƭ�ؤΥ��ե��å�
	�� 2    ����ƥ����륨�顼����1�쥳���ɥ�����
           2    ����ƥ����륨�顼�����쥳���ɿ�
	   2    ����ƥ����륨�顼��������ֺǸ����Ͽ�����쥳���ɤؤΥ��ե��å�

���� ##################################
 ����#  �������;����ΰ�˴ؤ�����  #
     ##################################

	   2	�������;���������Ƭ�ؤΥ��ե��å�

���� ##############################
 ����#  �ꥶ�����ΰ�˴ؤ�����  #
     ##############################

	   2	�ꥶ�����ΰ����Ƭ�ؤΥ��ե��å�


     ########################
     #  �����ƥ���󥨥ꥢ  #
     ########################

��������   1	�����ƥ�ξ��֤򤢤�魯�ե饰

	         ##################
		 #  �ե饰������  #
		 ##################

                    0	[reserved]
		����1	������
		����2	������
		����3	������
		����4	������
		����5	������
		����6	������
		����7	������
	   3	[reserved]
	  32    �����ƥ�ξ���ʥ����ƥ�̾�� 
	   4	�ޥ��󥷥ꥢ��ʥ�С�
           4	�ޥ��å��ʥ�С�
           4    [reserved]

-----------------------------------------------------------------------------
TOTAL    640 �Х���


 #######################################                      
 #  ALIVE, �ڡ����㡼��������󥨥ꥢ  #
 #######################################

	   1	���ߤ������٥�
	  16	ALIVE�켡������
	  16	ALIVE�������� 
          47    [reserved for pager call]

-----------------------------------------------------------------------------
TOTAL     80 �Х���


 ############################################################################## 
 #  �������ޤ�720�Х��ȡ������ΰ����Ƭ��256�Х��ȥХ�����꤫��Ϥޤ�褦��  #
 #  48�Х��Ȥ�[reserved]�Ȥ��ƥѥǥ��󥰤��롣                                #
 ##############################################################################

	  48	[reserved]


 ####################### 
 # ���ꥨ�顼������  #
 #######################

	 400  	1bit���顼����쥳����(25�Х���) ��  16

		 ####################
  		 #  �쥳���ɤ�����  #
		 ####################

			1�����ե饰

	        	����	 ##################
		 		 #  �ե饰������  #
		 		 ##################

				����0	ͭ��/̵��    0:̵�� 1:ͭ��
				����1	check��/̤   0:̤   1:��
				����2	[reserved]
				����3	������
				����4	������
				����5	������
				����6	������
				����7���� ����
	�� 		4 	���顼���ɥ쥹
		       14	ȯ�������ॹ�����
	   		4	����ɥ�����
	�� 		1	���ꥰ�롼��
	   		1       SIMM�������
	 100	2bit���顼����쥳����(25�Х���) �� 4

		 ####################
  		 #  �쥳���ɤ�����  #
		 ####################

			1	�ե饰

	        		 ##################
		 		 #  �ե饰������  #
		 		 ##################

				����0	ͭ��/̵��    0:̵�� 1:ͭ��
				����1	check��/̤   0:̤   1:��
				����2	[reserved]
				����3	������
				����4	������
				����5��	������
				����6	������
				����7	������
	�� 		4 	���顼���ɥ쥹
		       14	ȯ�������ॹ�����
	   		4	����ɥ�����
	�� 		1	���ꥰ�롼��
	   		1       SIMM�������

-----------------------------------------------------------------------------
TOTAL    500 �Х���


 ###############################################################################
 #  �������ޤ�1268�Х��ȡ������ΰ����Ƭ��256�Х��ȥХ�����꤫��Ϥޤ�褦��  #
 #  12�Х��Ȥ�[reserved]�Ȥ��ƥѥǥ��󥰤��롣                                 #
 ###############################################################################

	  12	[reserved]


 ##########################
 #  �����ƥ२�顼������  #
 ##########################

	2048	�����ƥ२�顼������ (1�쥳����512�Х��� �� 4 �� 2K) 

		 ####################
  		 #  �쥳���ɤ�����  #
		 ####################

			1	�ե饰
	        		
                                 ##################
		 		 #  �ե饰������  #
		 		 ##################

				����0	ͭ��/̵��    0:̵�� 1:ͭ��
				����1	check��/̤   0:̤   1:��
				����2   Dump/Dump SW 0:D    1:D SW
				����3   �����̵ͭ   0:̤   1:��
				����4	boot���     0:���� 1:�۾�
				����5	������
				����6	������
				����7	������
		       14	ȯ�������ॹ�����
		      496       �����ƥ२�顼����
                        1       [reserved]

-----------------------------------------------------------------------------
TOTAL   2048 �Х���


 ####################################################### 
 #  �������ޤ�3328�Х��ȡ����礦��256�Х��ȥХ������  #
 #######################################################

                       
 ###############################################################
 #  ����ƥ����륨�顼������ (1�쥳����128�Х��� �� 32 �� 4K)  #
 ###############################################################

	4096	����ƥ����륨�顼������ (1�쥳����128�Х��� �� 32 �� 4K) 

		 ####################
  		 #  �쥳���ɤ�����  #
                 ####################

			1	�ե饰
	        		 ##################
		 		 #  �ե饰������  #
		 		 ##################

				����0	ͭ��/̵��    0:̵�� 1:ͭ��
				����1	check��/̤   0:̤   1:��
				����2   Panic/Shutdown 0:P  1:S
				����3   [reserved]     
				����4	������
				����5	������
				����6	������
				����7	������
		       14	ȯ�������ॹ�����
		       20	������̾
		       80       ����ƥ����륨�顼����
                       13       [reserved]

-----------------------------------------------------------------------------
TOTAL   4096 �Х���


 ####################################################### 
 #  �������ޤ�7424�Х��ȡ����礦��256�Х��ȥХ������  #
 #######################################################


 ##############################
 #  ��������Ƚ���ѥǡ����ΰ�  #
 ##############################

 ��      256    [reserved]

-----------------------------------------------------------------------------
TOTAL    256 �Х���


 ############################################################### 
 #  �������ޤ�7680(7K+512)�Х��ȡ����礦��256�Х��ȥХ������  #
 ###############################################################


 ############################## 
 #  �ꥶ�����ΰ� (512�Х���)  #
 ##############################
 
	 512 	PAiNTS��?
	
-----------------------------------------------------------------------------
TOTAL    512 �Х���


 #############################################
 #  �������ޤ�8192(8K)�Х��ȡ�NVRAM�Τ��ä�  #
 #############################################

******************************************************************************/


#pragma pack(1)

/********************
 *                  *
 *  ����¤�����    *
 *                  *
 ********************/


/*
 *  WAS & PS����FW�ѥ��ꥨ�顼�����ΰ�
 */
typedef struct _MEM_ERR_REC {
	unsigned char 	mem_status;  /* ���ơ����� */
	unsigned char 	err_count;   /* 1bit���顼������� */
} MEM_ERR_REC, *pMEM_ERR_REC;


/*
 *  ALIVE�����ΰ�˴ؤ�����
 */
typedef struct _ALIVE_AREA_INFO {
	unsigned short offset_alive;
				/* ALIVE���󥨥ꥢ���ե��å� */
} ALIVE_AREA_INFO, *pALIVE_AREA_INFO;


/*
 *  ECC1bit���顼�����ΰ�˴ؤ�����
 */
typedef struct _ECC1_ERR_AREA_INFO {
	unsigned short offset_1biterr;	/* ���ꥢ����Ƭ�ؤΥ��ե��å� */
	unsigned short size_rec;	/* 1�쥳���ɥ����� */
	unsigned short num_rec;		/* ���쥳���ɿ� */
	unsigned short offset_latest;	/* �ǿ��쥳���ɥ��ե��å� */
	unsigned long read_data_latest; /* �ǿ��꡼�ɥ��顼�ǡ��� */
	unsigned char err_count_group0; /* ����G#0 ���顼������� */
	unsigned char err_count_group1; /* ����G#1 ���顼������� */
	unsigned char err_count_group2; /* ����G#2 ���顼������� */
	unsigned char err_count_group3; /* ����G#3 ���顼������� */
	unsigned char err_count_group4; /* ����G#4 ���顼������� */
	unsigned char err_count_group5; /* ����G#5 ���顼������� */
	unsigned char err_count_group6; /* ����G#6 ���顼������� */
	unsigned char err_count_group7; /* ����G#7 ���顼������� */
} ECC1_ERR_AREA_INFO, *pECC1_ERR_AREA_INFO;


/*
 *  ECC2bit���顼�����ΰ�˴ؤ�����
 */
typedef	struct _ECC2_ERR_AREA_INFO {
	unsigned short offset_2biterr;	/* ���ꥢ����Ƭ�ؤΥ��ե��å� */
	unsigned short size_rec;	/* 1�쥳���ɥ����� */
	unsigned short num_rec;		/* ���쥳���ɿ� */
	unsigned short offset_latest;	/* �ǿ��쥳���ɥ��ե��å� */
	unsigned long read_data_latest; /* �ǿ��꡼�ɥ��顼�ǡ��� */
	unsigned char simm_flag_group1; /* ����G#1��SIMM�ե饰 */
	unsigned char simm_flag_group2; /* ����G#2��SIMM�ե饰 */
	unsigned char simm_flag_group3; /* ����G#3��SIMM�ե饰 */
	unsigned char simm_flag_group4; /* ����G#4��SIMM�ե饰 */
	char reserved[4]; 		/* reserved */
} ECC2_ERR_AREA_INFO, *pECC2_ERR_AREA_INFO;


/*
 *  �����ƥ२�顼�����ΰ�˴ؤ�����
 */
typedef struct _SYSTEM_ERR_AREA_INFO {
	unsigned short offset_systemerr;/* ���ꥢ����Ƭ�ؤΥ��ե��å� */
	unsigned short size_rec;	/* 1�쥳���ɥ����� */
	unsigned short num_rec;		/* ���쥳���ɿ� */
	unsigned short offset_latest;	/* �ǿ��쥳���ɥ��ե��å� */
} SYSTEM_ERR_AREA_INFO, *pSYSTEM_ERR_AREA_INFO;


/*
 *  ����ƥ����륨�顼�����ΰ�˴ؤ�����
 */
typedef struct _CRITICAL_ERR_AREA_INFO {
	unsigned short offset_critical;	/* ���ꥢ����Ƭ�ؤΥ��ե��å� */
	unsigned short size_rec;	/* 1�쥳���ɥ����� */
	unsigned short num_rec;		/* ���쥳���ɿ� */
	unsigned short offset_latest;	/* �ǿ��쥳���ɥ��ե��å� */
} CRITICAL_ERR_AREA_INFO, *pCRITICAL_ERR_AREA_INFO;


/*
 *  ��������������¾�ξ����ΰ�˴ؤ�����
 */
typedef struct _MISC_AREA_INFO {
	unsigned short offset_misc; 
			      /* �����������ξ��󥨥ꥢ��Ƭ���ե��å� */
} MISC_AREA_INFO, *pMISC_AREA_INFO;


/*
 *  �ꥶ�����ΰ�˴ؤ�����
 */
typedef struct _RESERVE_AREA_INFO {
	unsigned short offset_reserve; 
				/* �ꥶ���֥��ꥢ��Ƭ���ե��å� */
} RESERVE_AREA_INFO, *pRESERVE_AREA_INFO;


/*
 *  �����ƥ���󥨥ꥢ
 *  49�Х���
 */

typedef struct _SYS_INFO {		
	unsigned char system_flag;	/* �����ƥ���֥ե饰 */
 	char reserved1[3];		/* 4byte alignment�ˤ��ʤ��� */
	char sys_description[32];	/* �����ƥ�ξ��� */
	unsigned long serical_num;  	/* �ޥ��󥷥ꥢ��ʥ�С� */
	unsigned long magic;		/* �ޥ��å��ʥ�С� */
 	char reserved2[4];		/* reserved */
} SYS_INFO, *pSYS_INFO;



/* 
 *  NVRAM�إå��� 
 *  640�Х���
 */

typedef struct _NVRAM_HEADER {
	MEM_ERR_REC mem_err_map[256];   /* ���ꥨ�顼����NT&NW���̥��ꥢ */
	unsigned char nvram_flag;	/* nvram�ξ��֥ե饰 */
	char when_formatted[14];	/* �ե����ޥåȥ����ॹ����� */
	char reserved[3];		/* 4byte alignment �ˤ��ʤ��� */
	ALIVE_AREA_INFO alive;   	/* ALIVE���󥨥ꥢ */
	ECC1_ERR_AREA_INFO ecc1bit_err; /* ECC1bit���顼���󥨥ꥢ */
	ECC2_ERR_AREA_INFO ecc2bit_err; /* ECC2bit���顼���󥨥ꥢ */
	SYSTEM_ERR_AREA_INFO system_err;/* �����ƥ२�顼���󥨥ꥢ */
	CRITICAL_ERR_AREA_INFO critical_err_log; 
					/* ����ƥ����륨�顼�������ꥢ */
	MISC_AREA_INFO misc; 		/* �����������󥨥ꥢ */
	RESERVE_AREA_INFO reserve; 	/* �ꥶ���֥��ꥢ���ե��å� */
	SYS_INFO system;		/* �����ƥ���� */
} NVRAM_HEADER, *pNVRAM_HEADER;



/*                      
 *  ALIVE, �ڡ����㡼��������󥨥ꥢ
 *  80�Х���
 */

typedef struct _ALIVE_INFO {		
	unsigned char alert_level;	/* �����٥륰 */
	char primary_destination[16];	/* �켡�����������ֹ� */
	char secondary_destinaiton[16];	/* �������������ֹ� */
 	char reserved[47];		/* reserved for pager call */
} ALIVE_INFO, *pALIVE_INFO;


/* 
 *  �������ޤ�720�Х��ȡ������ΰ����Ƭ��256�Х��ȥХ�����꤫��Ϥޤ�褦��
 *   48�Х��Ȥ�[reserved]�Ȥ��ƥѥǥ��󥰤��롣
 */

char reserved[48];


typedef struct _ECC1_ERR_REC {
	unsigned char record_flag;	/* �쥳���ɥե饰 */
	unsigned long err_address;	/* ���顼���ɥ쥹 */
	char when_happened[14];		/* ȯ�������ॹ����� */
	unsigned long syndrome;		/* ����ɥ����� */
	unsigned char specified_group;  /* ���ꥰ�롼�� */
	unsigned char specified_simm;   /* SIMM������� */
} ECC1_ERR_REC, *pECC1_ERR_REC;


typedef struct _ECC2_ERR_REC {
	unsigned char record_flag;	/* �쥳���ɥե饰 */
	unsigned long err_address;	/* ���顼���ɥ쥹 */
	char when_happened[14];		/* ȯ�������ॹ����� */
	unsigned long syndrome;		/* ����ɥ����� */
	unsigned char specified_group;  /* ���ꥰ�롼�� */
	unsigned char specified_simm;   /* SIMM������� */
} ECC2_ERR_REC, *pECC2_ERR_REC;


/* 
 * ���ꥨ�顼������
 *  500 �Х���
 */

ECC1_ERR_REC ecc1_err_rec_log[16];

ECC2_ERR_REC ecc2_err_rec_log[4];


/* 
 *  �������ޤ�1268�Х��ȡ������ΰ����Ƭ��256�Х��ȥХ�����꤫��Ϥޤ�褦��
 *   12�Х��Ȥ�[reserved]�Ȥ��ƥѥǥ��󥰤��롣
 */

char reserved2[12];


typedef struct _STOP_ERR_REC {
	unsigned char record_flag;	/* �쥳���ɥե饰 */
	char when_happened[14];		/* ȯ�������ॹ����� */
	char err_description[496];  	/* �����ƥ२�顼���� */
	char reserved[1]; 		/* reserved */
} STOP_ERR_REC, *pSTOP_ERR_REC;

/*
 *  ���åȥץ��顼������
 *  2048 �Х���
 */

STOP_ERR_REC stop_err_rec_log[4];


typedef struct _CRITICAL_ERR_REC {
	unsigned char record_flag;	/* �쥳���ɥե饰 */
	char when_happened[14];		/* ȯ�������ॹ����� */
	char source[14];		/* ������̾ */
	char err_description[496];  	/* ����ƥ����륨�顼���� */
	char reserved[13];		/* reserved */
} CRITICAL_ERR_REC, *pCRITICAL;


/*     ��                
 *  ����ƥ����륨�顼������ (1�쥳����128�Х��� �� 32 �� 4K)
 *  4096�Х���
 */

CRITICAL_ERR_REC critical_err_rec_log[32];


/*
 *  ��������Ƚ�������ǡ����ΰ�. 
 *  256�Х���
 */

char reserved3[256];			/* reserved */


/* 
 *  �ꥶ�����ΰ�(PAiNTS��?)
 *  512�Х���
 */
 
char reserved4[512];			/* reserved for paints ? */

#pragma pack(4)