/**
 * \file dma_private.h
 * \brief
 * \author Chris Wunderlich
 * \version 0.1.0.0
 * \date 29-Apr-2019
 *
 * \copyright Copyright (c) 2016 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct {
	uint32 RDCRC;
	uint32 SDCRC;
	uint32 SADR;
	uint32 DADR;
	uint32 ADICR;
	uint32 CHCFGR;
	uint32 SHADR;
	uint32 CHCSR;
} DMA_TRANSACTION_CONTROL_Type;


/** \brief Block Mode
 * Defines the number of DMA moves executed during one DMA transfer
 * Definition in DMA_CHCFGRx.BLKM
 */
typedef enum
{
	dma_chcfgrxxx_blkm_OneTransferHasOneMove = 0,  /**< \brief One DMA transfer has 1 DMA move */
	dma_chcfgrxxx_blkm_OneTransferHasTwoMoves,     /**< \brief One DMA transfer has 2 DMA moves */
	dma_chcfgrxxx_blkm_OneTransferHasFourMoves,    /**< \brief One DMA transfer has 4 DMA moves */
	dma_chcfgrxxx_blkm_OneTransferHasEightMoves,   /**< \brief One DMA transfer has 8 DMA moves */
	dma_chcfgrxxx_blkm_OneTransferHasSixteenMoves, /**< \brief One DMA transfer has 16 DMA moves */
	dma_chcfgrxxx_blkm_OneTransferHasThreeMoves,   /**< \brief One DMA transfer has 3 DMA moves */
	dma_chcfgrxxx_blkm_OneTransferHasFiveMoves,    /**< \brief One DMA transfer has 5 DMA moves */
	dma_chcfgrxxx_blkm_OneTransferHasNineMoves,    /**< \brief One DMA transfer has 9 DMA moves */
} DMA_CHCFGRx_BLKM_Type;

/** \brief Reset Request Only After Transaction
 * DMA channel control bit to determine if the DMA request state flag
 * (DMA channel TSR.CH) is reset after each DMA transfer.
 * Definition in DMA_CHCFGRx.RROAT
 */
typedef enum
{
	dma_chcfgrxxx_rroat_ResetAfterEachTransfer = 0,  /**< \brief DMA channel TSR.CH is reset after the start of each DMA transfer. A DMA request is required for each DMA transfer */
	dma_chcfgrxxx_rroat_ResetWhenTCountIsZero,       /**< \brief DMA channel TSR.CH is reset when CHSR.TCOUNT = 0 and after the completion of the last DMA transfer (i.e. on completion of the DMA transaction). One DMA request starts a complete DMA transaction */
} DMA_CHCFGRx_RROAT_Type;

/** \brief Channel Operation Mode
 * DMA channel TCS control to determine TSR.HTRE reset condition.
 * Definition in DMA_CHCFGRx.CHMODE
 */
typedef enum
{
	dma_chcfgrxxx_chmode_SingleMode = 0,  /**< \brief Single_Mode, is selected for DMA channel.
	After a DMA transaction, DMA channel is disabled for further hardware requests
	(TSR.HTRE is reset by hardware) TSR.HTRE must be set again by software for starting a new transaction*/
	dma_chcfgrxxx_chmode_ContinuousMode = 1,  /**< \brief Continuous_Mode, is selected for DMA channel.
	After a DMA transaction, bit TSR.HTRE remains set*/
} DMA_CHCFGRx_CHMODE_Type;

/** \brief Channel Data Width
 * DMA channel TCS data width for DMA read moves and DMA write moves
 * Definition in DMA_CHCFGRx.CHDW
 */
typedef enum
{
	dma_chcfgrxxx_chdw_DataBitWidth_8 = 0,  /**< \brief 8-bit data width for moves selected*/
	dma_chcfgrxxx_chdw_DataBitWidth_16,     /**< \brief 16-bit data width for moves selected*/
	dma_chcfgrxxx_chdw_DataBitWidth_32,     /**< \brief 32-bit data width for moves selected*/
	dma_chcfgrxxx_chdw_DataBitWidth_64,     /**< \brief 64-bit data width for moves selected*/
	dma_chcfgrxxx_chdw_DataBitWidth_128,    /**< \brief 128-bit data width for moves selected*/
	dma_chcfgrxxx_chdw_DataBitWidth_256,    /**< \brief 256-bit data width for moves selected*/
} DMA_CHCFGRx_CHDW_Type;


/** \brief Pattern Select
 * DMA channel TCS bit field to select the pattern detection operation (see
 * Functional Description). If PATSEL[1:0] is not equal to 00B then a ME
 * pattern detection operation defined by the channel data width (CHDW) will
 * be performed. PATSEL[2] selects the pattern read register. If a pattern
 * match is detected then a DMA channel interrupt shall be triggered.
 * Definition in DMA_CHCFGRx.PATSEL
 */
typedef enum
{
	dma_chcfgrxxx_patsel_NoPatternCompareOperation = 0,  /**< \brief No pattern compare operation*/
	dma_chcfgrxxx_patsel_CompareWithPRR0 = 1,  /**< \brief DMA read move data compared with PRR0*/
	dma_chcfgrxxx_patsel_CompareWithPRR1 = 7,  /**< \brief DMA read move data compared with PRR1*/
} DMA_CHCFGRx_PATSEL_Type;

/** \brief Swap Data CRC Byte Order
 * DMA channel TCS swap data CRC byte order
 * Definition in DMA_CHCFGRx.SWAP
 */
typedef enum
{
	dma_chcfgrxxx_swap_ByteOrderIsNotSwapped = 0,  /**< \brief Byte order is not swapped*/
	dma_chcfgrxxx_swap_ByteOrderIsSwapped = 1,  /**< \brief Byte order is swapped*/
} DMA_CHCFGRx_SWAP_Type;


/** \brief Peripheral Request Select
 * DMA channel TCS control bit field to select the source of a DMA request
 * Definition in DMA_CHCFGRx.PRSEL
 */
typedef enum
{
	dma_chcfgrxxx_prsel_HardwareRequestSelected = 0,  /**< \brief DMA hardware request selected*/
	dma_chcfgrxxx_prsel_DaisyChainRequestSelected = 1,  /**< \brief DMA daisy chain request selected*/
} DMA_CHCFGRx_PRSEL_Type;

/** \brief DMA Priority
 * This bit determines the DMA the request priority that is used when a move
 * operation related to channel z is requesting SPB-Bus. This bit has no
 * effect in channel prioritization inside the Move Engine x in.
 * Definition in DMA_CHCFGRx.DMAPRIO
 */
typedef enum
{
	dma_chcfgrxxx_dmaprio_LowPrioritySelected = 0,  /**< \brief Low priority selected */
	dma_chcfgrxxx_dmaprio_MediumPrioritySelected1 = 1,  /**< \brief Medium priority selected */
	dma_chcfgrxxx_dmaprio_MediumPrioritySelected2 = 2,  /**< \brief Medium priority selected */
	dma_chcfgrxxx_dmaprio_HighPrioritySelected = 3,  /**< \brief High priority selected */
} DMA_CHCFGRx_DMAPRIO_Type;

/** \brief Source Address Modification Factor
 * DMA channel TCS 32-bit source address modification factor and the channel
 * data width CHDW determines an address offset value by which the source
 * address is modified after each DMA move. If SCBE = 1B and CBLS = 0000B t
 * hen the source address is not modified.
 * Definition in DMA_ADICRc.SMF
 */
typedef enum
{
	dma_adicrxxx_smf_AddressOffsetIsCHDWx1 = 0, /**< \brief Address offset is 1 x CHDW */
	dma_adicrxxx_smf_AddressOffsetIsCHDWx2,     /**< \brief Address offset is 2 x CHDW */
	dma_adicrxxx_smf_AddressOffsetIsCHDWx4,     /**< \brief Address offset is 4 x CHDW*/
	dma_adicrxxx_smf_AddressOffsetIsCHDWx8,     /**< \brief Address offset is 8 x CHDW*/
	dma_adicrxxx_smf_AddressOffsetIsCHDWx16,    /**< \brief Address offset is 16 x CHDW*/
	dma_adicrxxx_smf_AddressOffsetIsCHDWx32,    /**< \brief Address offset is 32 x CHDW*/
	dma_adicrxxx_smf_AddressOffsetIsCHDWx64,    /**< \brief Address offset is 64 x CHDW*/
	dma_adicrxxx_smf_AddressOffsetIsCHDWx1128,  /**< \brief Address offset is 128 x CHDW*/
} DMA_ADICRc_SMF_Type;

/** \brief Increment of Source Address
 * DMA channel TCS control bit to determine if the address offset selected
 * by SMF will be added to or subtracted from the source address after each
 * DMA move. If SCBE = 1B and CBLS = 0000B then the source address is not modified.
 * Definition in DMA_ADICRc.INCS
 */
typedef enum
{
	dma_adicrxxx_incs_AddressOffsetIsSubtracted = 0, /**< \brief Address offset will be subtracted */
	dma_adicrxxx_incs_AddressOffsetIsAdded,     /**< \brief Address offset will be added*/
} DMA_ADICRc_INCS_Type;

/** \brief Destination Address Modification Factor
 * DMA channel TCS 32-bit destination address modification factor and the
 * channel data width CHDW determines an address offset value by which
 * the destination address is modified after each DMA move. If DCBE = 1B
 * and CBLD = 0000B then the destination address is not modified.
 * Definition in DMA_ADICRc.DMF
 */
typedef enum
{
	dma_adicrxxx_dmf_AddressOffsetIsCHDWx1 = 0, /**< \brief Address offset is 1 x CHDW */
	dma_adicrxxx_dmf_AddressOffsetIsCHDWx2,     /**< \brief Address offset is 2 x CHDW */
	dma_adicrxxx_dmf_AddressOffsetIsCHDWx4,     /**< \brief Address offset is 4 x CHDW*/
	dma_adicrxxx_dmf_AddressOffsetIsCHDWx8,     /**< \brief Address offset is 8 x CHDW*/
	dma_adicrxxx_dmf_AddressOffsetIsCHDWx16,    /**< \brief Address offset is 16 x CHDW*/
	dma_adicrxxx_dmf_AddressOffsetIsCHDWx32,    /**< \brief Address offset is 32 x CHDW*/
	dma_adicrxxx_dmf_AddressOffsetIsCHDWx64,    /**< \brief Address offset is 64 x CHDW*/
	dma_adicrxxx_dmf_AddressOffsetIsCHDWx1128,  /**< \brief Address offset is 128 x CHDW*/
} DMA_ADICRc_DMF_Type;

/** \brief Increment of Destination Address
 * DMA channel TCS control bit to determine if the address offset selected
 * by SMF will be added to or subtracted from the destination address after each
 * DMA move. If DCBE = 1B and CBLS = 0000B then the source address is not modified.
 * Definition in DMA_ADICRc.INCD
 */
typedef enum
{
	dma_adicrxxx_incd_AddressOffsetIsSubtracted = 0, /**< \brief Address offset will be subtracted */
	dma_adicrxxx_incd_AddressOffsetIsAdded,     /**< \brief Address offset will be added*/
} DMA_ADICRc_INCD_Type;

/** \brief Circular Buffer Length Source
 * DMA channel TCS circular buffer source address update control bit
 * determines which part of the 32-bit source address register remains
 * unchanged and is not updated after a DMA move operation.
 * Definition in DMA_ADICRc.CBLS
 */
typedef enum
{
	dma_adicrxxx_cbls_SourceAddress31to0 = 0, /**< \brief Source address SADR[31:0] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to1,     /**< \brief Source address SADR[31:1] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to2,     /**< \brief Source address SADR[31:2] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to3,     /**< \brief Source address SADR[31:3] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to4,     /**< \brief Source address SADR[31:4] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to5,     /**< \brief Source address SADR[31:5] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to6,     /**< \brief Source address SADR[31:6] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to7,     /**< \brief Source address SADR[31:7] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to8,     /**< \brief Source address SADR[31:8] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to9,     /**< \brief Source address SADR[31:9] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to10,    /**< \brief Source address SADR[31:10] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to11,    /**< \brief Source address SADR[31:11] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to12,    /**< \brief Source address SADR[31:12] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to13,    /**< \brief Source address SADR[31:13] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to14,    /**< \brief Source address SADR[31:14] is not updated*/
	dma_adicrxxx_cbls_SourceAddress31to15,    /**< \brief Source address SADR[31:15] is not updated*/
} DMA_ADICRc_CBLS_Type;

/** \brief Circular Buffer Length Destination
 * DMA channel TCS circular buffer destination address update control bit
 * determines which part of the 32-bit destination address register remains
 * unchanged and is not updated after a DMA move operation.
 * Definition in DMA_ADICRc.CBLD
 */
typedef enum
{
	dma_adicrxxx_cbld_DestinationAddress31to0 = 0, /**< \brief Destination address SADR[31:0] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to1,     /**< \brief Destination address SADR[31:1] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to2,     /**< \brief Destination address SADR[31:2] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to3,     /**< \brief Destination address SADR[31:3] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to4,     /**< \brief Destination address SADR[31:4] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to5,     /**< \brief Destination address SADR[31:5] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to6,     /**< \brief Destination address SADR[31:6] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to7,     /**< \brief Destination address SADR[31:7] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to8,     /**< \brief Destination address SADR[31:8] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to9,     /**< \brief Destination address SADR[31:9] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to10,    /**< \brief Destination address SADR[31:10] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to11,    /**< \brief Destination address SADR[31:11] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to12,    /**< \brief Destination address SADR[31:12] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to13,    /**< \brief Destination address SADR[31:13] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to14,    /**< \brief Destination address SADR[31:14] is not updated*/
	dma_adicrxxx_cbld_DestinationAddress31to15,    /**< \brief Destination address SADR[31:15] is not updated*/
} DMA_ADICRc_CBLD_Type;

/** \brief Shadow Control
 * DMA channel TCS shadow control determines the function of the shadow
 * address register.
 * Definition in DMA_ADICRc.SHCT
 */
typedef enum
{
	dma_adicrxxx_shct_MoveOperation = 0, /**< \brief */
	dma_adicrxxx_shct_ShadowOperationReadOnlyModeSourceAddress, /**< \brief */
	dma_adicrxxx_shct_ShadowOperationReadOnlyModeDestinationAddress, /**< \brief */
	dma_adicrxxx_shct_ShadowOperationDirectWriteModeSourceAddress = 5, /**< \brief */
	dma_adicrxxx_shct_ShadowOperationDirectWriteModeDestinationAddress, /**< \brief */
	dma_adicrxxx_shct_DMADoubleSourceBufferingWithSoftwareSwitchOnly = 8, /**< \brief */
	dma_adicrxxx_shct_DMADoubleSourceBufferingWithSoftwareSwitchAndAutomaticHardwareSwitch, /**< \brief */
	dma_adicrxxx_shct_DMADoubleDestinationBufferingWithSoftwareSwitchOnly, /**< \brief */
	dma_adicrxxx_shct_DMADoubleDestinationBufferingWithSoftwareSwitchAndAutomaticHardwareSwitch, /**< \brief */
	dma_adicrxxx_shct_DMALinkedList, /**< \brief */
	dma_adicrxxx_shct_AccumulatedLinkedList, /**< \brief */
	dma_adicrxxx_shct_SafeLinkedList, /**< \brief */
	dma_adicrxxx_shct_ConditionalLinkedList, /**< \brief */
} DMA_ADICRc_SHCT_Type;

/** \brief Source Circular Buffer Enable
 * DMA channel TCS source circular buffer enable.
 * Definition in DMA_ADICRc.SCBE
 */
typedef enum
{
	dma_adicrxxx_scbe_SourceCircularBufferDisabled = 0, /**< \brief Source circular buffer disabled*/
	dma_adicrxxx_scbe_SourceCircularBufferEnabled,     /**< \brief Source circular buffer enabled*/
} DMA_ADICRc_SCBE_Type;

/** \brief Destination Circular Buffer Enable
 * DMA channel TCS destination circular buffer enable.
 * Definition in DMA_ADICRc.DCBE
 */
typedef enum
{
	dma_adicrxxx_dcbe_DestinationCircularBufferDisabled = 0, /**< \brief Destination circular buffer disabled*/
	dma_adicrxxx_dcbe_DestinationCircularBufferEnabled,     /**< \brief Destination circular buffer enabled*/
} DMA_ADICRc_DCBE_Type;


/** \brief Time Stamp
 * DMA channel TCS control bit to enable the appendage of a timestamp
 * after the end of the last DMA Move during a DMA transaction.
 * Definition in DMA_ADICRc.STAMP
 */
typedef enum
{
	dma_adicrxxx_stamp_NoAction = 0, /**< \brief */
	dma_adicrxxx_stamp_TimestampIsAppended,     /**< \brief */
} DMA_ADICRc_STAMP_Type;

/** \brief Enable Transaction Request Lost Interrupt
 * This bit enables the generation of an interrupt when
 * TSRz.TRLz is set.
 * Definition in DMA_ADICRc.ETRL
 */
typedef enum
{
	dma_adicrxxx_etrl_NoInterruptOnLostEvent = 0,   /**< \brief */
	dma_adicrxxx_etrl_GenerateInterruptOnLostEvent,     /**< \brief */
} DMA_ADICRc_ETRL_Type;


/** \brief Wrap Source Enable
 * DMA channel TCS source buffer interrupt trigger enable/disable.
 * Definition in DMA_ADICRc.WRPSE
 */
typedef enum
{
	dma_adicrxxx_wrpse_WrapSourceBufferInterruptTriggerDiabled = 0, /**< \brief */
	dma_adicrxxx_wrpse_WrapSourceBufferInterruptTriggerEnabled,     /**< \brief */
} DMA_ADICRc_WRPSE_Type;

/** \brief Wrap Destination Enable
 * DMA channel TCS destination buffer interrupt trigger enable/disable.
 * Definition in DMA_ADICRc.WRPDE
 */
typedef enum
{
	dma_adicrxxx_wrpde_WrapDestinationBufferInterruptTriggerDiabled = 0, /**< \brief */
	dma_adicrxxx_wrpde_WrapDestinationBufferInterruptTriggerEnabled,     /**< \brief */
} DMA_ADICRc_WRPDE_Type;

/** \brief Interrupt Control
 * DMA channel TCS interrupt control
 * Definition in DMA_ADICRc.INTCT
 */
typedef enum
{
	dma_adicrxxx_intct_NoInterruptTCOUNTequalsIRDV = 0, /**< \brief */
	dma_adicrxxx_intct_NoInterruptTCOUNTisDecremented,  /**< \brief */
	dma_adicrxxx_intct_InterruptChangingTCOUNTandEqualsIRDV,  /**< \brief */
	dma_adicrxxx_intct_InterruptTCOUNTisDecremented,  /**< \brief */
} DMA_ADICRc_INTCT_Type;

#endif	/* end of file */

/*************************************************************************
 Development history of the file
 29Apr19  Chris.Wunderlich   Initial release


*************************************************************************/
