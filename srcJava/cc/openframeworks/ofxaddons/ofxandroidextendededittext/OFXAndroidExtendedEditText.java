package cc.openframeworks.ofxaddons.ofxandroidextendededittext;

import android.content.Context;
import android.view.KeyEvent;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.TextView.OnEditorActionListener;
import cc.openframeworks.ofxaddons.ofxandroidextendededittext.ExtendedEditText;


public class OFXAndroidExtendedEditText extends cc.openframeworks.OFAndroidObject {
	public String text="";
	private RelativeLayout rlayout;
	private ExtendedEditText eet;
	
	OFXAndroidExtendedEditText() {
        rlayout = (RelativeLayout) activity.findViewById(activity.getResources().getIdentifier("relativeLayout1", "id", activity.getPackageName()));
		eet = new ExtendedEditText(activity);
		eet.setOnEditorActionListener(new OnEditorActionListener() {
		    @Override
		    public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
		        boolean handled = false;
				text = eet.getText().toString();
				if (actionId == EditorInfo.IME_ACTION_DONE) {
					final InputMethodManager imm = (InputMethodManager) activity.getSystemService(Context.INPUT_METHOD_SERVICE);
					imm.hideSoftInputFromWindow(eet.getWindowToken(), 0);
		            //remove();
					eet.clearFocus();
					handled = true;
		        }
		        return handled;
		    }
		});
	}
	
	public void add(String _text, int x, int y, float size, String _hint) {
		final CharSequence t = (_text.length() == 0 ? "" : _text.subSequence(0, _text.length()));
		final CharSequence h = (_hint.length() == 0 ? "" : _hint.subSequence(0, _hint.length()));
		final ExtendedEditText et = eet;
		final int posX = x;
		final int posY = y;
		final float textSize = size;
		activity.runOnUiThread(new Runnable(){
			public void run() {
				et.setVisibility(EditText.VISIBLE);
				et.setBackgroundColor(0x00000000);
				et.setTextColor(0xffffffff);
				et.setHintTextColor(0x99ffffff);
				et.setTextSize(textSize);
				et.setSingleLine();
				et.setImeOptions(EditorInfo.IME_ACTION_DONE);
				rlayout.addView(et);

				RelativeLayout.LayoutParams params = (RelativeLayout.LayoutParams) et.getLayoutParams();
				params.leftMargin = posX;
				params.topMargin = posY;
				et.setLayoutParams(params);

				eet.setHint(h);
				eet.setText(t);
				//eet.requestFocus();
		        
				//final InputMethodManager imm = (InputMethodManager) activity.getSystemService(Context.INPUT_METHOD_SERVICE);
				//imm.showSoftInput(eet, InputMethodManager.SHOW_FORCED);
			}
		});
		text=_text;
	}
	
	
	public void remove() {
		final ExtendedEditText et = eet;
		activity.runOnUiThread(new Runnable(){
			public void run() {
				// UI code goes here
				et.setVisibility(EditText.INVISIBLE);
				et.setClickable(false);
				rlayout.removeView(et);
			}
		});
	}
	
	public boolean isShown() {
		return eet.isShown();
	}
		
	
	@Override
	protected void appPause() {
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void appResume() {
		// TODO Auto-generated method stub
		
	}

	@Override
	protected void appStop() {
		// TODO Auto-generated method stub
		
	}

}
