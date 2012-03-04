import wx

cfg = wx.Config('myconfig')
if cfg.Exists('username'):
	cfg.Write('username','')
	cfg.Write('password','')
	cfg.WriteBool('state',False)
