#include"public.h"


u8 chrg_o;

u8 full=0;
u8 chrging=1;
u8 chrg_cnt=0;
//100ms  0
void chrg_task(task* task_)
{
    if(chrg_o&& (USB_DET==0))
    {
        add_task_id(ui_chrgfree_id,ui_chrgfree_ms,ui_chrgfree_max,ui_id);
        full=0;
        bat.bat=get_bat();
        //uart_txnum(bat.bat,4);

    }
    else if(USB_DET&& (chrg_o==0))
    {
        task_->sucCnt=0;
        chrg_cnt=0;
        if(CHRG_FULL==0)
        {
            chrging=1;
        }
    }
    chrg_o=USB_DET;

    if(full)
    {
        task_->sucCnt=0;
        chrg_cnt=0;
        return;
    }
	if(USB_DET)
    {
        if(CHRG_FULL)
        {
            full=1;            
            bat.dian=4;
            if(get_bat()>390)
            {
                add_task_id(ui_chrgfull_id,ui_chrgfull_ms,ui_chrgfull_max,ui_id);
            }
            return;
        }
        if(chrging&&((task_list[ui_id].active==0)||(task_list[ui_id].id==ui_begin_id)))
        {
            chrging=0;
            add_task_id(ui_chrg_id,ui_chrg_ms,ui_chrg_max,ui_id);
        }
        task_->sucCnt++;

        if(task_->sucCnt>=250)
        {
            task_->sucCnt=0;
            chrg_cnt++;
            if(chrg_cnt>=48)
            {
                chrg_cnt=0;
                if(bat.dian<3){bat.dian++;}
            }
        }

    }
    else
    {
        chrg_cnt=0;
        task_->sucCnt=0;
    }

}
