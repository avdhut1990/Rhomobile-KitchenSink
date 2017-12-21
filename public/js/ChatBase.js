$(document).on('click', '.panel-heading span.icon_minim', function (e) {
	toggleChatBox($(this));
});

function toggleChatBox(switchButton){
	if (!switchButton.hasClass('panel-collapsed')) {
		switchButton.parents('.panel').find('.panel-body').slideUp();
		switchButton.parents('.panel').find('.panel-footer').slideUp();
		switchButton.addClass('panel-collapsed');
		switchButton.removeClass('glyphicon-minus').addClass('glyphicon-plus');
	}
	else {
		$.ajax({
			url: "/app/Chat/init",
			headers: {'Transition-Enabled': false},
			success: function(data){
			}
		});
		switchButton.parents('.panel').find('.panel-body').slideDown();
		switchButton.parents('.panel').find('.panel-footer').slideDown();
		switchButton.removeClass('panel-collapsed');
		switchButton.removeClass('glyphicon-plus').addClass('glyphicon-minus');
	}
}