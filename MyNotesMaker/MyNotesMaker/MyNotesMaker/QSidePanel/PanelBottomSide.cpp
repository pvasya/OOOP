#include "PanelBottomSide.hpp"

#include "side_panel_helpers.hpp"

PanelBottomSide::PanelBottomSide(QWidget *parent)
    : SidePanel(parent)
{

    this->getOpenedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_opened_bottom(this->getPanelSize(), parent_rect);
    };

    this->getClosedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_closed_bottom(this->getPanelSize(), parent_rect);
    };

    this->alignedHandlerRect = [](const QRect& panel_geom, const QSize& handler_size, qreal) -> QRect
    {
        return q_sp::rect_aligned_top_center(panel_geom, handler_size);
    };

    this->initialHandlerSize = []() -> QSize {
        return {70, 30};
    };

    this->updateHandler = [](const SidePanelState state, HandlerWidgetT* handler)
    {
        switch (state) {
        case SidePanelState::Opening: {
            QPixmap pixmap(":/img/img/expand_more_FILL0_wght400_GRAD0_opsz24.svg");
            handler->setIcon(QIcon(pixmap));
            handler->setIconSize(pixmap.size()); } break;
        case SidePanelState::Opened:  {
            QPixmap pixmap(":/img/img/expand_more_FILL0_wght400_GRAD0_opsz24.svg");
            handler->setIcon(QIcon(pixmap));
            handler->setIconSize(pixmap.size());} break;
        case SidePanelState::Closing: {
            QPixmap pixmap(":/img/img/border_color_FILL0_wght400_GRAD0_opsz24.svg");
            handler->setIcon(QIcon(pixmap));
            handler->setText("Tools");
            handler->setIconSize(pixmap.size());} break;
        case SidePanelState::Closed:  {
            QPixmap pixmap(":/img/img/border_color_FILL0_wght400_GRAD0_opsz24.svg");
            handler->setIcon(QIcon(pixmap));
            handler->setText("Tools");
            handler->setIconSize(pixmap.size());} break;
        default: break;
        }
    };
}

PanelBottomSide::~PanelBottomSide()
{

}
